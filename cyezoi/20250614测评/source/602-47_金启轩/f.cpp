#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, a[3005], m, b[105];
ll dp[5][5005];
int f, now;
void run(int flag) {
	memset(dp, 0LL, sizeof(dp));
	f = 0;
	for (int i = 1; i <= n; ++i) {
		now = i + f;
		if (i == flag && !f) {
			f = 1, i--;
			dp[0][now] = max(dp[0][now - 1], dp[1][now - 1]);
			dp[1][now] = dp[0][now - 1] + b[1];
		} else {
			dp[0][now] = max(dp[0][now - 1], dp[1][now - 1]);
			dp[1][now] = dp[0][now - 1] + a[i];
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; ++i) cin >> b[i];
	if (m == 0) {
		run(0);
		cout << max(dp[0][n], dp[1][n]) << endl;
	}
	else if (m == 1) {
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			run(i);
			ans = max(ans, max(dp[0][n + 1], dp[1][n + 1]));
		}
		a[++n] = b[1];
		run(0);
		ans = max(ans, max(dp[0][n], dp[1][n]));
		cout << ans << endl;
	}
	else cout << "Keine Ahnung\n";
	return 0;
}

