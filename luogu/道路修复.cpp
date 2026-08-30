#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
	int a, b, w, id; 
} e[1000005], al[200005];
int cur, c[15];
bool cmp(edge x, edge y){
	return x.w < y.w;
}
int f[10015];
void setup(){
	for (int i = 1; i <= 10010; i++)
		f[i] = i;
}
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> e[i].a >> e[i].b >> e[i].w;
		e[i].id = 0;
	}
	sort(e+1, e+m+1, cmp);
	setup();
	int ks = n-1;
	for (int i = 1; i <= m && ks > 0; i++){
		if (find(e[i].a) != find(e[i].b)){
			al[++cur] = e[i];
			merge(e[i].a, e[i].b);
		}
	}
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			int w;
			cin >> w;
			cur++;
			al[cur].a = n + i;
			al[cur].b = j;
			al[cur].w = w;
			al[cur].id = i; 
		}
	}
	sort(al+1, al+cur+1, cmp);
	long long ans = 1e18;
	for (int i = 0; i < (1 << k); i++){
		setup();
		long long sum = 0, num = 0;
		for (int j = 1; j <= k; j++)
			if ((i >> j-1) & 1) sum += c[j], num++;
		int ks = n + num - 1;
		for (int j = 1; j <= cur && ks > 0; j++)
			if (find(al[j].a) != find(al[j].b) && (al[j].id == 0 || (i >> al[j].id-1) & 1)){
				sum += al[j].w;
				merge(al[j].a, al[j].b);
			}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}

