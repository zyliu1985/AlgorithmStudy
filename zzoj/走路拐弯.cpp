#include <iostream>
#include <cmath>
#include <cstring>
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
int dp[55][55][6][2]; // 0为左到右，1为上到下 
char map[55][55];
int main(){
	freopen("turn.in", "r", stdin);
	freopen("turn.out", "w", stdout);
	int t = read();
	while (t--){
		memset(dp, 0, sizeof(dp));
		int n = read(), m = read();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		if (map[1][2] != 'H') dp[1][2][0][0] = 1;
		if (map[2][1] != 'H') dp[2][1][0][1] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++){
				if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1) || map[i][j] == 'H')
					continue;
				for (int k = 0; k <= m; k++){
					if (k != 0){
						dp[i][j][k][0] = dp[i][j-1][k][0] + dp[i][j-1][k-1][1];
						dp[i][j][k][1] = dp[i-1][j][k-1][0] + dp[i-1][j][k][1];
					} else {
						dp[i][j][k][0] = dp[i][j-1][k][0];
						dp[i][j][k][1] = dp[i-1][j][k][1];
					}
				}
			}
		int ans = 0;
		for (int i = 0; i <= m; i++)
			ans += dp[n][n][i][0] + dp[n][n][i][1];
		write(ans, '\n');
	}
	return 0;
}
