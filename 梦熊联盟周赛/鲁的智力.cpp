#include <iostream>
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
inline void write(int x){
	if (x < 0){
		putchar('-');
		write(-x);
		return;
	} 
	if (x / 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
int a[1005];
int main(){
	freopen("gio.in", "r", stdin);
	freopen("gio.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	int ans1 = 1e9, mini, ans2 = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] < ans1){
			ans1 = a[i];
			mini = i;
		}
	}
	for (int i = 1; i <= n; i++){
		if (i != mini)
			ans1 -= m - a[i];
		ans2 += a[i] - 1;
	}
	write(max(1, ans1)), putchar('\n'), write(min(m, ans2 + 1));
	return 0;
}
