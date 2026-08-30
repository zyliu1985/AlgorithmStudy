#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
long long dp[10005][7505];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout); 
	int n;
	cin >> n; 
	dp[0][2502] = 1;
	long long ans = 0;
	for (int i = 1; i <= 2 * n; i++){
		for (int j = - (n / 2); j <= n; j++){
			dp[i][j+2502] = (dp[i-1][j-1+2502] + dp[i-1][j+1+2502] * (j + 1 != n)) % mod;
			if (j == n) ans = (ans + dp[i][j+2502]) % mod; 
		}
	}
	cout << ans << '\n'; 
	return 0;
}



