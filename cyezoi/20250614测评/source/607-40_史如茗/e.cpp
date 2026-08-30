#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int k, n, m, a, b, y, t, h, ans = 1e9, v[N];
vector <int> g[N], l[N];
struct node
{
	int x, s;
};
queue <node> q;
void bfs(node u)
{
	q.push(u);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		if (u.s >= ans)
		{
			continue;
		}
		if (u.x == b)
		{
			if (ans == -1)
			{
				ans = u.s;
			}
			else ans = min(ans, u.s);
		}
		for (int i = 0; i < g[u.x].size(); i++)
		{
			y = g[u.x][i];
			t = u.s + l[u.x][i];
			if (u.s >= ans || u.s >= v[y])
			{
				continue;
			}
			v[y] = u.s;
			q.push(node{y, t});
		}
	}
}
int main()
{
	memset(v, 0x3f, sizeof(v));
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> t >> h;
		if (h)
		{
			continue;
		}
		g[a].push_back(b);
		l[a].push_back(t);
		g[b].push_back(a);
		l[b].push_back(t);
	}
	cin >> a >> b;
	bfs(node{a, 0});
	cout << (ans < 1000000000 ? ans : -1);
}
