#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3 + 5, K = 200 + 5;

struct node
{
	int u, t, h;
};

struct node2
{
	int u, h;
};

vector <node> g[N];
int k, n, m, s, t, ans = 1e18, dist[N][K];

void bfs()
{
	queue <node2> q;
	memset (dist, -1, sizeof dist);
	dist[s][0] = 0;
	q.push({s, 0});
	while (!q.empty())
	{
		int u = q.front().u, sumh = q.front().h; q.pop();
		for (auto nxt : g[u])
		{
			int v = nxt.u, nt = nxt.t, nh = nxt.h;
			if (sumh + nh >= k)	continue;
			if (dist[v][sumh + nh] != -1 && dist[v][sumh + nh] <= dist[u][sumh] + nt)	continue;
			dist[v][sumh + nh] = dist[u][sumh] + nt;
			q.push({v, sumh + nh});
		}
	}
}

signed main()
{
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, t, h;
		cin >> u >> v >> t >> h;
		g[u].push_back({v, t, h});
		g[v].push_back({u, t, h});
	}
	cin >> s >> t;
	bfs();
	for (int i = 0; i < k; i++)
		if (dist[t][i] != -1)	ans = min(ans, dist[t][i]);
	if (ans == (int)1e18)	cout << -1 << endl;
	else	cout << ans << endl;
	return 0;
}
