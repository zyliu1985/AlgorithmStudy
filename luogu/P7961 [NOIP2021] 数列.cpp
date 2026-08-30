#include <iostream>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;

const int mod = 998244353;
long long v[105][35], c[35][35];
int dp[35][105][35][35];
int popcount(int x){
	int re = 0;
	while (x > 0) x -= lowbit(x), re++;
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, mk;
	cin >> n >> m >> mk;
	for (int i = 0; i <= m; i++){
		cin >> v[i][1];
		v[i][0] = 1;
		for (int j = 2; j <= n; j++)
			v[i][j] = v[i][j-1] * v[i][1] % mod;
	}
	c[0][0] = 1;
	for (int i = 1; i <= n; i++){
		c[i][0] = 1, c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
	}
	dp[0][0][0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= n; k++)
				for (int l = 0; l < mk; l++){
					for (int p = 0; i + p <= n; p++)
						dp[i+p][j+1][(p+k)/2][l+(p+k)%2] = (dp[i+p][j+1][(p+k)/2][l+(p+k)%2] + (v[j][p] * dp[i][j][k][l] % mod) * c[i+p][p] % mod) % mod;
					}
//	for (int i = 0; i <= n; i++)
//		for (int j = 0; j <= m; j++)
//			for (int k = 0; k <= n; k++)
//				for (int l = 0; l <= mk; l++){
//					cout << i << ',' << j << ',' << k << ',' << l << ':' << dp[i][j][k][l] << '\n';
//				}
	long long ans = 0;
	for (int j = 0; j <= m+1; j++)
		for (int k = 0; k <= n; k++)
			for (int l = 0; l <= mk; l++){
				if (popcount(k) + l > mk) break;
				ans = (ans + dp[n][j][k][l]) % mod;
			}
	cout << ans << '\n';
	return 0;
}

