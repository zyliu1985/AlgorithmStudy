#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
string s;
int n, k;
long long dp[505][505][6];
// 0: ***...*
// 1: (.....)
// 2: (..)**(..)*(..)
// 3: (..)**(..)*(..)***
// 4: ***(..)**(..)*(..)
// 5: ***(..)**(..)*(..)***
bool decide(int l, int r, bool type){ // type=0: ***...*, type=1:(.....)
	if (type){
		if ((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?') && l != r) return true;
		else return false;
	} else {
		if (r - l + 1 > k) return false;
		for (int i = l; i <= r; i++)
			if (s[i] != '*' && s[i] != '?') return false;
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	cin >> s;
	s = ' ' + s;
	if (n == 1){
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++)
		dp[i][i][0] = decide(i, i, 0);
	for (int i = 1; i < n; i++){
		dp[i][i+1][0] = decide(i, i+1, 0);
		dp[i][i+1][1] = decide(i, i+1, 1);
	}
	for (int len = 3; len <= n; len++)
		for (int l = 1; l + len - 1 <= n; l++){
			int r = l + len - 1;
			dp[l][r][0] = decide(l, r, 0);
			dp[l][r][1] = decide(l, r, 1) * (dp[l+1][r-1][0] + 
											 dp[l+1][r-1][1] + 
											 dp[l+1][r-1][2] + 
											 dp[l+1][r-1][3] + 
											 dp[l+1][r-1][4]);
			for (int k = l; k <= r-1; k++){
				dp[l][r][2] += (dp[l][k][1] + dp[l][k][2] + dp[l][k][3]) * dp[k+1][r][1];
				dp[l][r][3] += (dp[l][k][2] + dp[l][k][1]) * dp[k+1][r][0];
				dp[l][r][4] += (dp[l][k][5] + dp[l][k][0] + dp[l][k][4]) * dp[k+1][r][1];
				dp[l][r][5] += dp[l][k][4] * dp[k+1][r][0];
				dp[l][r][2] %= mod;
				dp[l][r][3] %= mod;
				dp[l][r][4] %= mod;
				dp[l][r][5] %= mod;
			}
			dp[l][r][1] %= mod;
			dp[l][r][2] %= mod;
			dp[l][r][3] %= mod;
			dp[l][r][4] %= mod;
			dp[l][r][5] %= mod;
		}
	cout << (dp[1][n][1] + dp[1][n][2]) % mod << '\n';
	return 0;
}

