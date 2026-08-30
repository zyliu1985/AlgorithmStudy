#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, u, v, w, t, x, y, d[2005][205];
struct T{
	int x, w, t;
	bool operator< (const T& o) const
	{
		return t > o.t;
	}
};
vector<T> e[2005];
priority_queue<T> q;
signed main()
{
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> t >> w;
		e[u].push_back({v, w, t});
		e[v].push_back({u, w, t});
	}
	cin >> x >> y;
	q.push({x, 0, 0});
	memset(d, 0x3f, sizeof d);
	for (int i = 0; i <= k; i++) d[x][i] = 0;
	while (q.size())
	{
		x = q.top().x, w = q.top().w, t = q.top().t;
		q.pop();
		if (x == y)
		{
			cout << t;
			return 0;
		}
		for (T i : e[x])
		{
			if (w + i.w >= k) continue;
			if (d[i.x][w + i.w] > d[x][w] + i.t)
			{
				d[i.x][w + i.w] = d[x][w] + i.t;
				for (int j = w + i.w + 1; j < k; j++)
					d[i.x][j] = min(d[i.x][j], d[x][w] + i.t);
				q.push({i.x, w + i.w, t + i.t});
			}
		}
	}
	return 0;
}
