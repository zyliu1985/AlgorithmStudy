#include <iostream>
#include <algorithm>
using namespace std;

int f[40005];
int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y){
	int zx = find(x), zy = find(y);
	if (zx != zy) f[zx] = zy;
}
struct edge{
	int a, b, c;
} v[100005];
bool cmp(edge x, edge y){
	return x.c < y.c;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++)
		cin >> v[i].a >> v[i].b >> v[i].c;
	sort(v+1, v+m+1, cmp);
	int cnt = n-1;
	long long ans1, ans2;
	ans1 = ans2 = 0;
	for (int i = 1; i <= m && cnt; i++)
		if (find(v[i].a) != find(v[i].b)){
			ans1 += v[i].c;
			merge(v[i].a, v[i].b);
		}
	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}
