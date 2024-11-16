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
inline void write(int x, char end = 0){
	if (x < 0){
		putchar('-');
		write(-x);
		return;
	}
	int len = x ? 0 : 1, tx = x;
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
const int MOD = 1e9 + 7;
int dp[2005][2005];
int main(){
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	int n = read(), k = read();
	for (int i = 1; i <= n; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= k; i++)
		for (int j = 1; j <= n; j++)
			for (int m = j; m <= n; m += j)
				dp[i][m] = (dp[i][m] + dp[i-1][j]) % MOD;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + dp[k][i]) % MOD;
	write(ans, '\n');
	return 0;
}
