#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;
int box[505];
bool s[505];
int dp[505][505][505];
long long frac[505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	frac[0] = 1;
	for (int i = 1; i <= n; i++)
		frac[i] = (frac[i-1] * i) % mod;
	for (int i = 1; i <= n; i++){
		char c;
		cin >> c;
		s[i] = (c == '1');
	}
	for (int i = 1; i <= n; i++){
		int c;
		cin >> c;
		box[c]++;
	}
	for (int i = 1; i <= n; i++)
		box[i] += box[i-1];
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= i; k++){
//				cout << i << ',' << j << ',' << k << ':' << dp[i][j][k] << '\n';
				if (s[i+1]){
					// 1:不满足，不录用
					dp[i+1][j][k+1] = (dp[i+1][j][k+1] + dp[i][j][k] * 1ll * (box[i-j] - k) % mod) % mod;
					// 2:合法，录用（贡献最后算）
					dp[i+1][j+1][k] = (dp[i+1][j+1][k] * 1ll + dp[i][j][k]) % mod;
					// 3:不合法，录用，负贡献
					dp[i+1][j+1][k+1] = (dp[i+1][j+1][k+1] - dp[i][j][k] * 1ll * (box[i-j] - k) % mod) % mod;
				} else {
					dp[i+1][j][k] = (dp[i+1][j][k] * 1ll + dp[i][j][k]) % mod;
				} 
			}
	long long ans = 0;
	for (int j = m; j <= n; j++){
		for (int k = 0; k <= n; k++)
			ans = (ans + dp[n][j][k] * 1ll * frac[n - k] % mod) % mod;
	}
	cout << (ans + mod) % mod << '\n';
	return 0;
}

