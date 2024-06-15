#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int dfn[10005], low[10005], color[10005], colornum[10005], dis[10005], cnt, co, ans;
bool in[10005], vis[10005];
vector<int> v[10005], g[10005];
stack<int> st;
void tarjan(int x){
	dfn[x] = low[x] = ++cnt;
	st.push(x);
	in[x] = true;
	for (int i = 0; i < v[x].size(); i++){
		if (dfn[v[x][i]] == 0){
			tarjan(v[x][i]);
			low[x] = min(low[x], low[v[x][i]]);
		}
		if (in[v[x][i]]) low[x] = min(low[x], low[v[x][i]]);
	}
	if (dfn[x] == low[x]){
		co++;
		while (!st.empty()){
			int p = st.top();
			st.pop();
			color[p] = co;
			colornum[co]++;
			in[p] = false;
			if (p == x) break;
		}
	}
}
void dfs(int x){
	vis[x] = true;
	dis[x]++;
	for (int i = 0; i < g[x].size(); i++)
		if (!vis[g[x][i]])
			dfs(g[x][i]);
}
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	// Ëõµã
	for (int i = 1; i <= n; i++)
		if (dfn[i] == 0)
			tarjan(i);
	// ½¨ÐÂÍ¼
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < v[i].size(); j++)
			if (color[i] != color[v[i][j]])
				g[color[i]].push_back(color[v[i][j]]);
	for (int i = 1; i <= co; i++){
		dfs(i);
		memset(vis, false, sizeof(vis));
	}
	for (int i = 1; i <= co; i++)
		if (dis[i] == co)
			ans += colornum[i];
	cout << ans << endl;
	return 0;
}