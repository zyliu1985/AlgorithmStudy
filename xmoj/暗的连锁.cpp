#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int f[30][100005], d[100005];
int cf[100005], scf[100005];
vector<int> v[100005];
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
void hy(int x, int fa){
	scf[x] = cf[x];
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			hy(v[x][i], x);
			scf[x] += scf[v[x][i]];
		}
}
int main(){
//	freopen("yam0.in", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
	cin >> n >> m;
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	d[1] = 1;
	dfs(1, 0);
	init();
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		cf[lca(x, y)] -= 2;
		cf[x]++, cf[y]++;
	}
	hy(1, 0);
	int ans = 0;
//	for (int i = 2; i <= n; i++)
//		cout << scf[i] << ' ';
	for (int i = 2; i <= n; i++)
		if (scf[i] == 0){
			ans += m;
		} else if (scf[i] == 1) ans++;
	cout << ans << '\n';
	return 0;
}



