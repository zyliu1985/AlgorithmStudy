#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3000 + 5, M = 100 + 5;

int n, m, a[N], b[M], dp[N][2];

void solve1()
{
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
		dp[i][1] = dp[i - 1][0] + a[i];
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
	exit(0);
}

void solve2()
{
	int ans = 0;
	dp[0][0] = 0, dp[0][1] = b[1];
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
		dp[i][1] = dp[i - 1][0] + a[i];
	}
	ans = max(dp[n][0], dp[n][1]);
	for (int j = 1; j <= n; j++)
	{
		int flag = 0;
		memset (dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++)
		{
			dp[i + flag][0] = max(dp[i - 1 + flag][1], dp[i - 1 + flag][0]);
			dp[i + flag][1] = dp[i - 1 + flag][0] + a[i];
			if (j == i)
			{
				flag = 1;
				dp[i + flag][0] = max(dp[i - 1 + flag][1], dp[i - 1 + flag][0]);
				dp[i + flag][1] = dp[i - 1 + flag][0] + b[1];
			}
		}
		ans = max(dp[n + 1][0], dp[n + 1][1]);
	}
	cout << ans << endl;
	exit(0);
}

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	if (m == 0)	solve1();
	if (m == 1)	solve2();
	return 0;
}
