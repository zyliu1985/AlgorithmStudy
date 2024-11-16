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
int a[20], ansa[20];
int main(){
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = i;
	int ans = 1e9;
	do{
		int sum = 0;
		for (int i = 1; i < n; i++)
			sum += a[i] * a[i+1];
		sum += a[n] * a[1];
		if (sum < ans){
			for (int i = 1; i <= n; i++)
				ansa[i] = a[i];
			ans = sum;
		}
	} while (next_permutation(a+1, a+n+1));
	write(ans);
	for (int i = 1; i <= n; i++)
		write(ansa[i], ' ');
	endl();
	return 0;
}

