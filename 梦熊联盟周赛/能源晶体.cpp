#include <iostream>
#include <cmath>
using namespace std;

inline int read(){
	int re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = (re << 1) + (re << 3) + (c - '0');
		c = getchar();
	}
	return re * type;
}
inline void write(long long x, char end = '\n'){
	if (x < 0){
		putchar('-');
		write(-x, end);
		return;
	}
	long long len = x ? 0 : 1, tx = x;
	while (x > 0){
		x /= 10;
		len++;
	}
	while (len--){
		putchar(tx / pow(10, len) + '0');
		tx %= int(pow(10, len));
	}
	putchar(end);
}
inline void endl(){
	putchar('\n');
}
const int MOD = 998244353;
long long dp[5005][5005];
int main(){
	freopen("energy.in", "r", stdin);
	freopen("energy.out", "w", stdout);
	int k = read(), n = read();
	for (int i = 1; i <= n; i++){
		dp[i][i] = 1;
		for (int j = 1; j <= k; j++){
//			write(dp[i][j], ' ');
			if (i + j <= 5000)
				dp[i][i+j] = (dp[i][i+j] + dp[i][j]) % MOD; 
			dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
		}
//		endl(); 
	}
	write(dp[n][k]);
	return 0;
}
