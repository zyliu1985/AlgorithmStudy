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
struct edge{
	int u, v, w;
} e[100005];
struct que{
	int k, u, id, ans;
} qu[100005];
int f[100005], size[100005];
int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y){
	x = find(x), y = find(y);
	if (x != y){
		f[x] = y;
		size[y] += size[x];
	}
}
bool cmp(edge x, edge y){
	return x.w > y.w;
}
bool pmc1(que x, que y){
	return x.k > y.k;
}
bool pmc2(que x, que y){
	return x.id < y.id;
}
int main(){
	freopen("lockdown.in", "r", stdin);
	freopen("lockdown.out", "w", stdout);
	for (int i = 1; i <= 1e5; i++)
		f[i] = i, size[i] = 1;
	int n = read(), q = read();
	for (int i = 1; i < n; i++)
		e[i].u = read(), e[i].v = read(), e[i].w = read();
	sort(e+1, e+n+1, cmp);
	for (int i = 1; i <= q; i++){
		qu[i].k = read(), qu[i].u = read();
		qu[i].id = i;
	}
	sort(qu+1, qu+q+1, pmc1);
	int cnt = 0;
	for (int i = 1; i <= q; i++){
		while (e[cnt+1].w >= qu[i].k){
			cnt++;
			merge(e[cnt].u, e[cnt].v);
		}
		qu[i].ans = size[find(qu[i].u)] - 1;
//		cout << qu[i].k << ',' << qu[i].u << ':' << cnt << "=>" << qu[i].ans << endl;
	}
	sort(qu+1, qu+q+1, pmc2);
	for (int i = 1; i <= q; i++)
		write(qu[i].ans, '\n');
	return 0;
}
