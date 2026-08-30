#include <iostream>
#include <algorithm>
using namespace std;

long long dp[1000005];
const int mod = 1e9 + 7;
const int inv2 = 500000004;
int main(){
	freopen("trade.in", "r", stdin);
	freopen("trade.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++){
		dp[i] = ((((dp[i-1] * (2 * (i-1)) % mod) * (2 * (i-1) + 1) % mod) * inv2 % mod + (2 * (i-1) + 1) * dp[i-1] % mod) % mod) * i % mod;
	}
	cout << dp[n] << '\n';
	return 0;
}

