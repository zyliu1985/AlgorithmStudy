#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;
int dp[505][505];
long long x, y;
void exgcd(long long a, long long b){
	if (!b){
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a % b);
	int t = x;
	x = y;
	y = t - (a / b) * y;
} 
int frac(long long a, long long b){ // a / b
//	return a * qpow(b, mod - 2) % mod;
	x = y = 0;
	exgcd(b, mod);
	x = (x % mod + mod) % mod;
	return (a * x) % mod;
}
int main(){
	freopen("a.in", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		memset(dp, 0, sizeof(dp));
		while (m--){
			int l, r;
			cin >> l >> r;
			long long sum;
			for (int i = 1; i < l; i++){
				sum = 0;
				for (int k = l; k <= r; k++)
					sum = (sum + dp[i][k]) % mod;
				for (int j = l; j <= r; j++){
					dp[i][j] = frac(sum, r - l + 1);
				}
			}
			
			for (int i = r+1; i <= n; i++){
				sum = 0;
				for (int k = l; k <= r; k++)
					sum = (sum + dp[k][i]) % mod;
				for (int j = l; j <= r; j++){
					dp[j][i] = frac(sum, r - l + 1);
				}
			}
			
			for (int i = l; i <= r; i++)
				for (int j = i+1; j <= r; j++)
					dp[i][j] = frac(1, 2);
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i+1; j <= n; j++)
				ans = (ans + dp[i][j]) % mod;
		cout << ans << '\n';
	}
	return 0;
}
