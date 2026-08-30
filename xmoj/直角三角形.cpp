#include <iostream>
#include <cstdio>
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
int main(){
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	int a = read(), b = read();
	if (a > b) swap(a, b);
	if (a == b) printf("%.3lf", sqrt(pow(b, 2) + pow(a, 2)));
	else printf("%.3lf", sqrt(pow(b, 2) - pow(a, 2)));
	return 0;
}

