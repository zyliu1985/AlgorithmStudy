#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int f[30][500005], d[500005];
vector<int> v[500005];
void dfs(int x, int fa){
	d[x] = d[fa] + 1;
	f[0][x] = fa;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa)
			dfs(v[x][i], x);
}
int n;
void init(){
	for (int i = 1; i <= 25; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = f[i-1][f[i-1][j]];
}

int lca(int x, int y){
	if (d[x] < d[y]) swap(x, y);
	int dxy = d[x] - d[y];
	for (int i = 0; dxy > 0; i++){
		if (dxy & 1) x = f[i][x];
		dxy >>= 1;
	}
	while (x != y){
		for (int i = 25; i >= 1; i--){
			if (f[i][x] != f[i][y]){
				x = f[i][x], y = f[i][y];
				break;
			}
		}
		x = f[0][x], y = f[0][y];
	}
	return x;
}
int main(){
//	ios::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
    int m; 
	cin >> n >> m;
	for (int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	d[1] = 1;
	dfs(1, 0);
	init();
	int lcab, lcbc, lcca, plan1, plan2, plan3;
	for (int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		lcab = lca(a, b);
		lcbc = lca(b, c);
		lcca = lca(c, a);
		plan1 = (d[a] - d[lcab]) + (d[b] - d[lcab]) + (d[c] - d[lca(lcab, c)]) + (d[lcab] - d[lca(lcab, c)]); 
		plan2 = (d[b] - d[lcbc]) + (d[c] - d[lcbc]) + (d[a] - d[lca(lcbc, a)]) + (d[lcbc] - d[lca(lcbc, a)]); 
		plan3 = (d[c] - d[lcca]) + (d[a] - d[lcca]) + (d[b] - d[lca(lcca, b)]) + (d[lcca] - d[lca(lcca, b)]); 
		int ans = 1e9, ansid;
		if (plan1 < ans){
			ans = plan1;
			ansid = lcab;
		}
		if (plan2 < ans){
			ans = plan2;
			ansid = lcbc;
		}
		if (plan3 < ans){
			ans = plan3;
			ansid = lcca;
		}
		printf("%d %d\n", ansid, ans);
//		cout << ansid << ' ' << ans << '\n'; 
	}
	return 0;
}



