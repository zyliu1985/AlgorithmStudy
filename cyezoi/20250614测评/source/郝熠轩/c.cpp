#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[5005], f[5005][5005], ans;
signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i - j < 1 || i + j > n) break;
			f[i - j][i + j] = f[i - j + 1][i + j - 1] + abs(a[i + j] - a[i - j]);
		}
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i - j + 1 < 1 || i + j > n) break;
			f[i - j + 1][i + j] = f[i - j + 2][i + j - 1] + abs(a[i + j] - a[i - j + 1]);
		}
	for (int i = 1; i <= n; i++)
	{
		ans = 1e18;
		for (int j = 1; j <= n - i + 1; j++) ans = min(ans, f[j][j + i - 1]);
		cout << ans << " ";
	}
	return 0;
}
