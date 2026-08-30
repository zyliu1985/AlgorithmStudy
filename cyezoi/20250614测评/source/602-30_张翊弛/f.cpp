#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3005;
const int M = 105;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m, a[N], b[M], f[N][M][2], dp[N][2];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	if (m == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + a[i];
		}
		cout << max(dp[n][0], dp[n][1]);
		return 0;
	}
	sort(b + 1, b + n + 1);
	memset(f, -0x3f, sizeof f);
	f[0][0][0] = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= 1; k++)
			{
				if (f[i][j][k] == INF)
					continue;
				if (i < n)
				{
					f[i + 1][j][0] = max(f[i + 1][j][0], f[i][j][k]);
					if (k == 0)
						f[i + 1][j][1] = max(f[i + 1][j][1], f[i][j][0] + a[i]);
				}
				if (j < m)
				{
					f[i][j + 1][0] = max(f[i][j + 1][0], f[i][j][k]);
					if (k == 0)
						f[i][j + 1][1] = max(f[i][j + 1][1], f[i][j][0] + b[i]);
				}
			}
		}
	}
	int ans = max(f[n][m][0], f[n][m][1]);
	cout << ans;
}

