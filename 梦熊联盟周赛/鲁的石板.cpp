#include <iostream>
#include <cmath>
using namespace std;

const int mod = 1e9 + 7;
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
int qpow(long long x, int up){
	if (up == 0) return 1;
	if (up & 1) return (qpow((x * x) % mod, up / 2) * x) % mod;
	else return qpow((x * x) % mod, up / 2);
}
int main(){
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	int t = read();
	while (t--){
		int n = read(), m = read();
		if (n & 1)
			write(qpow(m-1, n) + 1, '\n');
		else
			write(qpow(m-1, n) + m - 1, '\n');
	}
	return 0;
}
