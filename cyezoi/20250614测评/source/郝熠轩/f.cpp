#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[3005], dp[3005], ans;
void solve()
{
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
	ans = max(ans, dp[n]);
}
signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	if (!m)
	{
		solve();
		cout << ans;
		return 0;
	}
	cin >> a[++n];
	for (int i = n; i >= 1; i--)
	{
		solve();
		swap(a[i], a[i - 1]);
	}
	cout << ans;
	return 0;
}
