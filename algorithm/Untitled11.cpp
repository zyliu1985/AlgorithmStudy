#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int x, len, lim;
};
struct q_node{
	int x, d;
	friend bool operator > (const node x, const node y){
		return x.d < y.d;
	}
}
struct n_node{
	int x, len;
};
vector<node> v[1005], fv[1005];
vector<n_node> nv[1005];
int dis[1005];
bool vis[1005];
priority_queue<q_node> q;
void dij(int sta){
	dis[sta] = 0;
	q.push({sta, 0});
	while (!q.empty()){
		int x = q.front().x;
		q.pop();
		if (vis[x]) continue;
		for (int i = 0; i < v[x].size(); i++)
			if (dis[v[x][i].x] > dis[c])
	}
}
int main(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++){
		int a, b, d, len, lim;
		cin >> a >> b >> d >> len >> lim;
		bool flag = false;
		if (lim == 0) flag = true;
		if (d == 0)
			if (!flag){
				v[a].push_back({b, len, lim});
				fv[b].push_back({a, len, lim});
			} else nv[a].push_back({b, len});
		else
			if (!flag){
				v[a].push_back({b, len, lim});
				v[b].push_back({a, len, lim});
				fv[a].push_back({b, len, lim});
				fv[b].push_back({a, len, lim});
			} else {
				nv[a].push_back({b, len});
				nv[b].push_back({a, len});
			}
	}
	for (int i = 1; i <= n; i++){
		if (nv[i].size() == 0) continue;
		for (int j = 0; j < fv[i].size(); j++)
			for (int k = 0; k < nv[i].size(); k++)
				v[fv[i][j].x].push_back({nv[i][k].x, fv[i][j].len + nv[i][k].len, fv[i][j].lim});
	}
	dij(s);
	cout << dis[t] << endl;
	return 0;
}