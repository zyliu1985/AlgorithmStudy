#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
struct Node
{
	int v, t, h;
	bool operator < (const Node &a) const
	{
		return a.t > t;
	}
};
bool vis[N];
int k, n, m, a, b, f[N][205];
vector<Node> g[N];
priority_queue<Node> q;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n >> m;
	for (int i = 1, u, v, t, h; i <= m; i++)
	{
		cin >> u >> v >> t >> h;
		g[u].push_back({v, t, h});
		g[v].push_back({u, t, h});
	}
	cin >> a >> b;
	q.push({a, 0, 0});
	memset(f, 0x3f, sizeof (f));
	f[a][0] = 0;
	while (q.size())
	{
		Node now = q.top();
		q.pop();
		int u = now.v;
		for (auto &it : g[u])
		{
			int v = it.v, t = it.t, h = it.h;
			int nh = now.h + h, nt = now.t + t;
			if (nh >= k)
				continue;
			if (nt >= f[v][nh])
				continue;
			f[v][nh] = nt;
			q.push({v, nt, nh});
		}
	}
	int minn = 0x3f3f3f3f;
	for (int i = 0; i < k; i++)
		minn = min(minn, f[b][i]);
	if (minn == 0x3f3f3f3f)
		cout << -1;
	else
		cout << minn;
}
