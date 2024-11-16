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
int a[105];
bool dp[100005];
int main(){
	freopen("printer.in", "r", stdin);
	freopen("printer.out", "w", stdout);
	int n = read(), sum = 0;
	for (int i = 1; i <= n; i++){
		a[i] = read();
		sum += a[i];
	}
	dp[0] = true;
	sum = (sum + 1) / 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 1e5; j++)
			dp[j] |= dp[j - a[i]];
	for (int d = 0; d <= 1e3; d++)
		if (dp[sum-d] || dp[sum+d]){
			write(sum+d);
			return 0;
		} 
	return 0;
}
