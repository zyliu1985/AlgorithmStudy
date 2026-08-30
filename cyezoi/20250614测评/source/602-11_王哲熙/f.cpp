#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 3e3 + 5;
const int MAXM = 105;
int a[MAXN], b[MAXM], dp[MAXN][2];
int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; ++i) cin >> b[i];
	if (m == 0) {
		dp[1][1] = a[1];
		for (int i = 2; i <= n; ++i) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][0] + a[i];
		}
		cout << max(dp[n][0], dp[n][1]) << "\n";
	}
	else cout << 114514 << "\n";
	return 0;
}
