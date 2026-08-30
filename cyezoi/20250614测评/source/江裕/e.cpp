#include <bits/stdc++.h>

using namespace std;

struct node
{
	int id, w, mosun;
};
vector<node> G[2005];
int vis[2005];
int n, m, qd, zd, k;
int ans = 0x3f3f3f3f;

void dfs(int u, int time, int totm)
{
//	cout << u << " " << time << " " << totm << "\n";
	if(u == zd) 
	{
//		cout << "UPD!!! " << ans << " " << time << "\n";
		ans = min(ans, time);
		return;
	}
	for(auto v : G[u])
	{
		if(vis[v.id]) continue;
		if(totm + v.mosun >= k) continue;
		vis[v.id] = 1;
		dfs(v.id, time + v.w, totm + v.mosun);
		vis[v.id] = 0;
	}
	return;
}

int main()
{
	cin >> k >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int u, v, t, h;
		cin >> u >> v >> t >> h;
		G[u].push_back({v, t, h});
		G[v].push_back({u, t, h});
	}
	cin >> qd >> zd;
	dfs(qd, 0, 0);
	if(ans == 0x3f3f3f3f) puts("-1");
	else cout << ans << "\n";
	return 0;
}
