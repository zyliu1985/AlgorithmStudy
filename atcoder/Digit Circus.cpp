#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod = 998244353;
string s;
int n;
long long dp[505][3][1 << 10][2][2];
bool get(int num, int x){
	return (num >> x) & 1;
}
int calc(int num){
	int re = 0;
	while (num > 0){
		re++;
		num -= (num&-num);
	}
	return re;
}
int norm(int x){
	x %= 3;
	x += 3;
	x %= 3;
	return x;
}
void print(int x){
	for (int d = 0; d <= 9; d++)
		cout << ((x >> d) & 1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for (int d = 0; d <= s[1] - '0'; d++){
		if (d == 0){
			dp[1][norm(d)][0][0][1] = 1;
		} else if (d == s[1] - '0'){
			dp[1][norm(d)][1<<d][1][0] = 1;
		} else {
			dp[1][norm(d)][1<<d][0][0] = 1;
		}
	}
	for (int i = 1; i < n; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < (1 << 10); k++){
//				if(dp[i][j][k][0][0] + dp[i][j][k][0][1] + dp[i][j][k][1][0] != 0){
//					cout << i << ',' << j << ',';
//					print(k);
//					cout << ':' << dp[i][j][k][0][0] + dp[i][j][k][0][1] + dp[i][j][k][1][0] << '\n';
//				}
				for (int d = 0; d <= 9; d++){
					// 0 0
					dp[i+1][norm(j+d)][k|(1<<d)][0][0] = (dp[i+1][norm(j+d)][k|(1<<d)][0][0] + dp[i][j][k][0][0]) % mod;
					// 0 1
					if (d == 0) dp[i+1][j][k][0][1] = (dp[i+1][j][k][0][1] + dp[i][j][k][0][1]) % mod;
					else dp[i+1][norm(j+d)][k|(1<<d)][0][0] = (dp[i+1][norm(j+d)][k|(1<<d)][0][0] + dp[i][j][k][0][1]) % mod;
					if (d <= s[i+1] - '0'){
						// 1 0
						dp[i+1][norm(j+d)][k|(1<<d)][(d == s[i+1] - '0')][0] = (dp[i+1][norm(j+d)][k|(1<<d)][(d == s[i+1] - '0')][0] + dp[i][j][k][1][0]) % mod;
					}
				}
			}
		}
	}
//	for (int j = 0; j < 3; j++){
//			for (int k = 0; k < (1 << 10); k++){
//				if (calc(k) > n) continue;
//				cout << n << ',' << j << ',';
//				print(k);
//				cout << ':' << dp[n][j][k][0][0] << ',' << dp[n][j][k][0][1] << ',' << dp[n][j][k][1][0] << '\n';
//			}
//		}
	long long ans = 0;
	for (int k = 0; k < (1 << 10); k++){
		if (get(k, 3) && calc(k) != 3){
			// 有3
			ans = (ans + dp[n][1][k][0][0]) % mod;
			ans = (ans + dp[n][1][k][1][0]) % mod;
			ans = (ans + dp[n][2][k][0][0]) % mod;
			ans = (ans + dp[n][2][k][1][0]) % mod;
		} else if ((!get(k, 3)) && calc(k) == 3){
			// 三个数
			ans = (ans + dp[n][1][k][0][0]) % mod;
			ans = (ans + dp[n][1][k][1][0]) % mod;
			ans = (ans + dp[n][2][k][0][0]) % mod;
			ans = (ans + dp[n][2][k][1][0]) % mod;
		} else if ((!get(k, 3)) && calc(k) != 3){
			// mod 3
			ans = (ans + dp[n][0][k][0][0]) % mod; 
			ans = (ans + dp[n][0][k][1][0]) % mod; 
		}
	}
	cout << ans << '\n';
	return 0;
}

