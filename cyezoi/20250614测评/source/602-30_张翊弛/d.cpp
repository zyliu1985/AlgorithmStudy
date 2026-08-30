#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int G, p, g[N], a[N];
bool vis[N];
bool check(int len)
{
	int cnt = 1;
	for (int i = 1; i <= len; i++)
		a[i] = g[i];
	memset(vis, 0, sizeof(vis));
	sort(a + 1, a + len + 1);
	for (int i = 1; i <= len; i++)
	{
		if (vis[a[i]])
			return 0;
		vis[cnt++] = 1;
	}
	return 1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> G >> p;
	for (int i = 1; i <= p; i++)
		cin >> g[i];
	int l = 1, r = p, ans;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	cout << ans;
}
