#include <iostream>
#include <cmath>
using namespace std;

inline long long read(){
	long long re = 0, type = 1;
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
inline void write(unsigned long long x, char end = 0){
	if (x < 0){
		putchar('-');
		write(-x);
		return;
	}
	unsigned long long len = x ? 0 : 1, tx = x;
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
int a[100005];
int main(){
	write(~0x7f7f7f7f7f7f7f7f, '\n');
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	int n = read(), ans = 0;
	long long m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	int l = 1, r = 0;
	long long sum = 0;
	while (r < n){
		sum += a[++r];
		while (sum > m)
			sum -= a[l++];
		if (sum == m) ans++;
	}
	return 0;
}
