#include <iostream>
#include <cmath>
#include <algorithm>
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
struct node{
	int l, r;
} tr[100005];
bool cmp(node x, node y){
	if (x.l != y.l) return x.l < y.l;
	return x.r > y.r;
}
int maxr[100005], ans;
bool flag[100005];
int main(){
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++){
		int a = read(), h = read();
		tr[i] = node{a - h, a + h};
	}
	sort(tr+1, tr+n+1, cmp);
	for (int i = 1; i <= n; i++)
		maxr[i] = max(maxr[i-1], tr[i].r);
	for (int i = 1; i <= n; i++){
//		cout << maxr[i - 1] << endl;
		if (maxr[i-1] >= tr[i].r){
			flag[i] = false;
		} else {
			flag[i] = true;
			ans++;
		}
		if (tr[i-1].l == tr[i].l && tr[i-1].r == tr[i].r && flag[i-1])
			ans--;
	}
	write(ans, '\n');
	return 0;
}
