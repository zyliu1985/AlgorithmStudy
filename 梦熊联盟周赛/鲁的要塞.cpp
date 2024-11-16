#include <iostream>
#include <algorithm>
#include <cstring>
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
struct node{
	int x, y;
} d[105];
long long ans[105], f[105], n, k;
void calc(int x, int y){
	for (int i = 1; i <= n; i++)
		f[i] = abs(d[i].x - x) + abs(d[i].y - y);
	sort(f+1, f+n+1);
	long long sum = 0;
	for (int i = 1; i <= k; i++){
		sum += f[i];
		ans[i] = min(ans[i], sum);
	}
}
int main(){
	freopen("base.in", "r", stdin);
	freopen("base.out", "w", stdout);
	memset(ans, 0x7f, sizeof(ans));
	n = read(), k = read();
	for (int i = 1; i <= n; i++)
		d[i].x = read(), d[i].y = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			calc(d[i].x, d[j].y);
	for (int i = 1; i <= k; i++)
		write(ans[i]);
	return ans[1];
}
