#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


int n, m;
int dfn[80005], low[80005], col[80005], nf[80005], co, clk, s;
long long ans;
long long dis[80005], val[80005];
bool in[80005], vis[80005];
queue<int> q;
stack<int> st;
struct node{
	int x, w1, w2;
};
vector<node> v[80005], g[80005];
void tbpx(){
	for (int i = 1; i <= co; i++)
		if (nf[i] == 0){
			q.push(i);
			vis[i] = true;
		}
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 0; i < g[x].size(); i++)
			if (!vis[g[x][i].x]){
				nf[g[x][i].x]--;
				dis[g[x][i].x] = max(dis[g[x][i].x], dis[x] + g[x][i].w1 + val[g[x][i].x]);
				if (nf[g[x][i].x] == 0){
					ans = max(ans, dis[g[x][i].x]);
					q.push(g[x][i].x);
					vis[g[x][i].x] = true;
				}
			}
	}
}
void tarjan(int x){
	dfn[x] = low[x] = ++clk;
	st.push(x);
	in[x] = true;
	for (int i = 0; i < v[x].size(); i++){
		if (dfn[v[x][i].x] == 0){
			tarjan(v[x][i].x);
			low[x] = min(low[x], low[v[x][i].x]);
		} else if (in[v[x][i].x]) low[x] = min(low[x], dfn[v[x][i].x]);
	}
	if (dfn[x] == low[x]){
		co++;
		while (!st.empty()){
			int t = st.top();
			st.pop();
			in[t] = false;
			col[t] = co;
			if (t == x) break;
		}
	}
}
long long cul(int x, double u){
	u *= 10;
	long long re = x;
	while (x > 0){
		x = x * u / 10;
		re += x;
	}
	return re;
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y, w1;
		double u;
		long long w2;
		cin >> x >> y >> w1 >> u;
		w2 = cul(w1, u);
		v[x].push_back({y, w1, w2});
	}
	cin >> s;
	tarjan(s);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < v[i].size(); j++)
			if (col[i] != col[v[i][j].x]){
				g[col[i]].push_back({col[v[i][j].x], v[i][j].w1, 0});
				nf[col[v[i][j].x]]++;
			} else
				val[col[i]] += v[i][j].w2;
	memset(dis, -0x3f, sizeof(dis));
	dis[col[s]] = val[col[s]];
	tbpx();
	cout << ans << endl;
	return 0;
}