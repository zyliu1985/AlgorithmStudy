#include <iostream>

using namespace std;

int n, m, a[3010], b[110];
int ans = 0;
void countt(int A[], int N) {
	int dp[3010] = {0};
	dp[1] = a[1], dp[2] = a[2];
	for (int i = 3; i <= N; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
	for (int i = 1; i <= N; i++) ans = max(ans, dp[i]);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int j = 1; j <= m; j++)
		cin >> b[j];
	if (m == 0)  {
		countt(a, n);
		cout << ans << "\n";
	}
	else if (m == 1) {
		int c[3010];
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) c[j] = a[i];
			int t = c[i];
			c[i] = b[1];
			for (int j = i + 1; j <= n + 1; j++) {
				int k = c[j];
				c[j] = t;
				t = k;
			}
			countt(c, n + 1);
			maxx = max(ans, maxx);
		}
		cout << maxx << "\n";
	}
	return 0;
}
