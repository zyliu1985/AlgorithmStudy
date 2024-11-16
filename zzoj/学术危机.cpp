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
long long a[500005], n, k, l;
bool cmp(int x, int y){
	return x > y;
}
bool check(int h){
	long long cnt = 0; // ²îÖµ¼ÆÊý
	for (int i = 1; i <= h; i++){
		if (h - a[i] > k) return false;
		else cnt += max(0ll, h - a[i]);
	}
	return (cnt <= k * l);
}
int main(){
	freopen("hesis.in", "r", stdin);
	freopen("hesis.out", "w", stdout);
	n = read(), k = read(), l = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a+1, a+n+1, cmp);
	int l = 1, r = n;
	while (l < r){
		int mid = (l + r + 1) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	write(l, '\n');
	return 0;
}
