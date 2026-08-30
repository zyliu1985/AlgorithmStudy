#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// ×ó-ÓÒ+2000 
long long dp[20][4000][2];
const int O = 2000;
long long res(long long x){
	long long re = 0;
	while (x > 0){
		re = re * 10 + (x % 10);
		x /= 10;
	}
	return re;
}
long long solve(long long x){
	if (x == 0) return 0;
	int len = 0;
	long long t = x;
	while (t > 0){
		t /= 10;
		len++;
	}
	x = res(x);
	t = x;
	long long ans = 0;
	for (int ctr = 1; ctr <= len; ctr++){
		memset(dp, 0, sizeof(dp));
		dp[0][O][1] = 1;
		x = t;
		for (int i = 0; i < len; i++){
			int now = x % 10;
			for (int j = O - 1500; j <= O + 1500; j++)
				for (int d = 0; d < 10; d++){
					int newj = j + d * (ctr - i - 1);
					// 0
					dp[i+1][newj][0] += dp[i][j][0];
					if (d <= now){
						// 1
						dp[i+1][newj][(d == now)] += dp[i][j][1];
					}
				}
			x /= 10;
		}
		ans += dp[len][O][0] + dp[len][O][1];
	}
	return ans - len;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long l, r;
	cin >> l >> r;
	cout << solve(r) - solve(l-1) << '\n';
	return 0;
}

