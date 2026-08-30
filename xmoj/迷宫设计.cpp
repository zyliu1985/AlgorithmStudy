#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
	int a, b, w;
} e[4000005];
int cur = 0;
bool cmp(edge x, edge y){
	return x.w < y.w;
}
int f[4000005];
int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y){
	int zx = find(x), zy = find(y);
	if (zx != zy){
		f[zx] = zy;
	}
}
int x[2005], y[2005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	int lst = 0;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= m; i++)
		cin >> y[i];
	sort(x+1, x+n+1), sort(y+1, y+m+1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			e[++cur] = {i + (j-1) * (n+1), i + j * (n+1), x[i] - x[i-1]};
	for (int j = 1; j <= m; j++)
		e[++cur] = {n + 1 + (j-1) * (n+1), n + 1 + j * (n+1), a - x[n]};
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			e[++cur] = {i + (j-1) * (n+1), i + 1 + (j-1) * (n+1), y[i] - y[i-1]};
	for (int j = 1; j <= n; j++)
		e[++cur] = {m + 1 + (j-1) * (n+1), m + 2 + (j-1) * (n+1), b - y[n]};
	for (int i = 1; i <= cur; i++)
		cout << e[i].a << ' ' << e[i].b << ' ' << e[i].w << '\n'; 
	for (int i = 1; i <= (n+1) * (m+1); i++)
		f[i] = i;
	sort(e+1, e+n+1, cmp);
	int ans = 0, k = (n+1) * (m+1) - 1;
	for (int i = 1; i <= cur && k > 0; i++)
		if (find(e[i].a) != find(e[i].b)){
			merge(e[i].a, e[i].b);
			ans += e[i].w;
			k--;
		}
	cout << ans << '\n';
	return 0;
}

