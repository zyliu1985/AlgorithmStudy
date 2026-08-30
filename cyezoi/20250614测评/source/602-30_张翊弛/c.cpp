#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, h[N], f[N][N], g[N][N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int mid = 1; mid <= n; mid++)
	{
		f[mid][0] = 0;
		for (int i = 1; i <= min(mid - 1, n - mid); i++)
			f[mid][i] = f[mid][i - 1] + abs(h[mid - i] - h[mid + i]);
	}
	for (int mid = 1; mid < n; mid++)
	{
		g[mid][0] = abs(h[mid] - h[mid + 1]);
		for (int i = 1; i <= min(mid - 1, n - mid - 1); i++)
			g[mid][i] = g[mid][i - 1] + abs(h[mid - i] - h[mid + i + 1]);
	}
	for (int i = 1; i <= n; i ++)
	{
		int ans = INT_MAX, l = i / 2;
		if (i % 2 == 0)
			for (int mid = l; mid <= n - l; mid++)
				ans = min(ans, g[mid][l - 1]);
		else
			for (int mid = l + 1; mid <= n - l; mid ++)
				ans = min(ans, f[mid][l]);
		cout << ans << " ";
	}
}
