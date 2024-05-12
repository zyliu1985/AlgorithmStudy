#include <iostream>
#include <algorithm>
using namespace std;

int f[2005];
struct node{
	int x, y, w;
} e[10005];
bool cmp(node x, node y){
	return x.w < y.w;
}
int find(int x){
	if (f[x] == x) return x;
	int y = find(f[x]);
	f[x] = y;
	return y;
}
void merge(int x, int y){
	int zx = find(x);
	int zy = find(y);
	if (zx != zy)
		f[zx] = zy;
}
int main(){
	for (int i = 1; i <= 2000; i++) f[i] = i;
	int n, m;
	cin >> n >> m;
	int ans = 0, cur = 0;
	for (int i = 1; i <= m; i++){
		int p, u, v, w;
		cin >> p >> u >> v >> w;
		if (p == 1){
			ans += w;
			merge(u, v);
		} else {
			e[++cur] = {u, v, w};
		}
	}
	sort(e+1, e+cur+1, cmp);
	for (int i = 1; i <= cur; i++){
		int x = e[i].x;
		int y = e[i].y;
		if (find(x) == find(y)) continue;
		ans += e[i].w;
		merge(x, y);
	}
	cout << ans << endl;
	return 0;
}