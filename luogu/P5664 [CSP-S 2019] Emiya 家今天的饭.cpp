#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;
long long a[105][2005], s[105];
long long dp[105][205], ans1 = 1, ans2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			s[i] = (s[i] + a[i][j]) % mod;
		}
		ans1 = (ans1 * (s[i] + 1)) % mod;
	}
	ans1 = (ans1 - 1 + mod) % mod; 
	for (int c = 1; c <= m; c++){
		dp[0][n] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = -n; j <= n; j++){
				dp[i][j+n] = 0;
				dp[i][j+n] = (dp[i][j+n] + dp[i-1][j+n]) % mod;
				if (j != -n) dp[i][j+n] = (dp[i][j+n] + a[i][c]*dp[i-1][j+n-1] % mod) % mod;
				if (j != n) dp[i][j+n] = (dp[i][j+n] + (s[i] - a[i][c])*dp[i-1][j+n+1] % mod + mod) % mod;
			}
		for (int i = 1; i <= n; i++)
			ans2 = (ans2 + dp[n][i+n]) % mod;
	}
	cout << (ans1 + mod - ans2) % mod << '\n';
	return 0;
}

