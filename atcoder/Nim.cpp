#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;
long long dp[65][10][10][10][2][2][2];
int len;
long long chai(long long x){
	long long re = 0;
	while (x > 0){
		len++;
		re = (re << 1) | (x & 1);
		x >>= 1;
	}
	return re;
}
int gcd(int x, int y){
	if (x % y == 0) return y;
	return gcd(y, x % y);
}
int lcm(int x, int y){
	return x * y / gcd(x, y);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	long long N = n;
	n = chai(n);
	dp[0][0][0][0][1][1][1] = 1;
	int cur = 0; 
	for (int i = 0; i < len; i++){
		cur++;
		int now = n & 1; 
		for (int ma = 0; ma < a; ma++)
			for (int mb = 0; mb < b; mb++)
				for (int mc = 0; mc < c; mc++)
					for (int da = 0; da < 2; da++)
						for (int db = 0; db < 2; db++){
							// 0 0 0
							dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][0][0][0] = (dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][0][0][0] + dp[i][ma][mb][mc][0][0][0]) % mod;
							if (da <= now){
								// 1 0 0
								dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][(da==now)][0][0] = (dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][(da==now)][0][0] + dp[i][ma][mb][mc][1][0][0]) % mod;
								if (db <= now){
									// 1 1 0
									dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][(da==now)][(db==now)][0] = (dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][(da==now)][(db==now)][0] + dp[i][ma][mb][mc][1][1][0]) % mod;
									if ((da ^ db) <= now){
										// 1 1 1
										dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][(da==now)][(db==now)][((da^db)==now)] = (dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][(da==now)][(db==now)][((da^db)==now)] + dp[i][ma][mb][mc][1][1][1]) % mod;
									}
								}
								if ((da ^ db) <= now){
									// 1 0 1
									dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][(da==now)][0][((da^db)==now)] = (dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][(da==now)][0][((da^db)==now)] + dp[i][ma][mb][mc][1][0][1]) % mod;
								}
							}
							if (db <= now){
								// 0 1 0
								dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][0][(db==now)][0] = (dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][0][(db==now)][0] + dp[i][ma][mb][mc][0][1][0]) % mod;
								if ((da ^ db) <= now){
									// 0 1 1
									dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][0][(db==now)][((da^db)==now)] = (dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][0][(db==now)][((da^db)==now)] + dp[i][ma][mb][mc][0][1][1]) % mod;
								}
							}
							if ((da ^ db) <= now){
								// 0 0 1
								dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][0][0][((da^db)==now)] = (dp[i+1][(ma*2+da)%a][(mb*2+db)%b][(mc*2+(da^db))%c][0][0][((da^db)==now)] + dp[i][ma][mb][mc][0][0][1]) % mod;
							}
						}
		n >>= 1;
	}
	long long ans = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				ans = (ans + dp[cur][0][0][0][i][j][k]) % mod;
	ans -= (N / lcm(a, b) + N / lcm(b, c) + N / lcm(a, c) + 1) % mod;
	ans += mod;
	ans %= mod;
	cout << ans << '\n';
	return 0;
}

