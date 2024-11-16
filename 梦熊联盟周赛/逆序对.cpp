#include <iostream>
#include <algorithm>
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
inline void write(int x, char end = '\n'){
	if (x < 0){
		putchar('-');
		write(-x, end);
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
inline void endl(){
	putchar('\n');
}
const int MOD = 1e9 + 7, NI = (1e9 + 8) / 2;
int a[1005], n, m, val;
long long dp[2][1005][1005];
namespace Debug{
	void print(int x){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
				write((dp[x][i][j] * val) % MOD, ' ');
			endl();
		}
	}
}
int main(){
//	freopen("inverse.in", "r", stdin);
//	freopen("inverse.out", "w", stdout); 
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i] > a[j]){
				dp[0][i][j] = 1; 
				dp[1][i][j] = 1;
			}
	val = 1;
	Debug::print(0); 
	bool last = 0, now = 1;
	for (int _ = 1; _ <= m; _++){
		val = (val * 2) % MOD;
		int c = read(), d = read();
		if (c > d)
			swap(c, d);
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++){
//				if (i == j) continue;
//				bool flag = true;
//				if (i != c && i != d && j != c && j != d)
//					dp[_][i][j] = (dp[_][i][j] + (dp[_-1][i][j] * 2) % MOD) % MOD, flag = false;
//				else if ((i == c && j == d) || (j == c && i == d)){
//					flag = false;
//					dp[_][j][i] = (dp[_][j][i] + dp[_-1][i][j]) % MOD;
//					dp[_][i][j] = (dp[_][i][j] + dp[_-1][i][j]) % MOD;
//				} else if (i == c && j != d){
//					flag = false;
//					dp[_][d][j] = (dp[_][d][j] + dp[_-1][i][j]) % MOD;
//					dp[_][i][j] = (dp[_][i][j] + dp[_-1][i][j]) % MOD;
//				} else if (i == d && j != c){
//					flag = false;
//					dp[_][c][j] = (dp[_][c][j] + dp[_-1][i][j]) % MOD;
//					dp[_][i][j] = (dp[_][i][j] + dp[_-1][i][j]) % MOD;
//				} else if (i != c && j == d){
//					flag = false;
//					dp[_][i][c] = (dp[_][i][c] + dp[_-1][i][j]) % MOD;
//					dp[_][i][j] = (dp[_][i][j] + dp[_-1][i][j]) % MOD;
//				} else if (i != d && j == c){
//					flag = false;
//					dp[_][i][d] = (dp[_][i][d] + dp[_-1][i][j]) % MOD;
//					dp[_][i][j] = (dp[_][i][j] + dp[_-1][i][j]) % MOD;
//				}
//				if (flag){
//					write(_, ':');
//					write(i, ',');
//					write(j, '\n');
//					exit(0);
//				}
//			}
		
		// i = c, j = d || j = c, i = d
		dp[now][d][c] = (((dp[last][d][c] + dp[last][c][d]) % MOD) * NI) % MOD;
		Debug::print(now);
		for (int j = 1; j <= n; j++){
			if (j != d){
				dp[now][d][j] += (((dp[last][d][j] + dp[last][c][j]) % MOD) * NI) % MOD;
				dp[now][d][j] %= MOD;
			}
			write(j, ':');
			endl(); 
			Debug::print(now);
		}
		dp[last][d][c] = dp[now][d][c];
		for (int j = 1; j <= n; j++){
			if (j != d)
				dp[last][d][j] = dp[now][d][j];
		}
		swap(last, now);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			ans = (ans + (dp[m % 2][i][j] * val) % MOD) % MOD;
	write(ans);
	return 0;
}
/*
3 2
2 1 3
1 2
1 3

3
*/

/*
3 1
2 1 3
1 2
 
1
*/
