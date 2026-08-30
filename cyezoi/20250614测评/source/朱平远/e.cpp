//500pts * (20% + 20%) = 200pts
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct node
{
	int v, t, h;
};
vector<node> g[2005];
bool used[2005];
int d[2005];
int main()
{
	memset(d, -1, sizeof(d));
	cin >> k >> n >> m;
	if(k != 1)
	{
		cout << -1;
		return 0;
	}
	for(int i = 1; i <= m; i++)
	{
		int a, b, t, h;
		cin >> a >> b >> t >> h;
		if(h)
			continue;
		g[a].push_back({b, t, h});
		g[b].push_back({a, t, h});
	}
	int u, v;
	cin >> u >> v;
	d[u] = 0;
	for(int t = 1; t < n; t++)
	{
		int id = u;
		int mn = 5e9;
		for(int i = 1; i <= n; i++)
			if(!used[i] && d[i] != -1 && mn > d[i])
				mn = d[i], id = i;
		used[id] = 1;
		for(int i = 0; i < g[id].size(); i++)
		{
			d[g[id][i].v] = min(d[g[id][i].v], d[id] + g[id][i].t);
			if(d[g[id][i].v] == -1)
				d[g[id][i].v] = d[id] + g[id][i].t;
		}
	}
	cout << d[v];
}
/*
1 4 7 
1 2 4 0
1 3 7 0
3 1 8 0 
3 2 2 0
4 2 1 0
3 4 1 0
1 4 6 0
1 4


1 5 6
1 2 2 0
1 3 1 0
4 1 2 0
2 4 6 0
3 5 5 0
5 4 3 0
1 5
*/
