#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[200005];
int sz[200005], f[20][200005], d[200005];
int tra, trb;
int n;
void dfs(int x, int fa){
	d[x] = d[fa] + 1;
	sz[x] = 1;
	f[0][x] = fa;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			dfs(v[x][i], x);
			sz[x] += sz[v[x][i]]; 
		}
}
void init(){
	for (int i = 1; i <= 18; i++)
		for (int j = 0; j < n; j++)
			f[i][j] = f[i-1][f[i-1][j]];
}
int lca(int x, int y){
	if (d[y] > d[x]) swap(x, y);
	int dd = d[x] - d[y];
	for (int i = 18; i >= 0; i--)
		if (dd >= (1 << i)){
			dd -= (1 << i);
			x = f[i][x];
		}
	if (x == y) return x;
	for (int i = 18; i >= 0; i--)
		if (f[i][x] != f[i][y]){
			x = f[i][x];
			y = f[i][y];
		}
	return f[0][x];
}
int fd(int x){
	int dd = d[x] - 2;
	for (int i = 18; i >= 0; i--)
		if (dd >= (1 << i)){
			dd -= (1 << i);
			x = f[i][x];
		}
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0, 0);
	init();
	long long ans = 0;
	for (int i = 0; i < v[0].size(); i++)
		ans += (sz[0] - sz[v[0][i]] - 1) * 1ll * sz[v[0][i]];
	ans /= 2; 
	ans += n;
	for (int i = 1; i < n; i++){
		int la = lca(i, tra);
		int lb = lca(i, trb);
		if (la == i || lb == i){
		} else if (la == tra){
			tra = i;
		} else if (lb == trb){
			if (trb == 0 && lca(tra, i) != 0) break;
			trb = i;
		} else {
			break;
		}
		if (trb != 0) ans += sz[tra] * 1ll * sz[trb];
		else ans += sz[tra] * 1ll * (sz[0] - sz[fd(tra)]);
	}
	cout << ans << '\n';
	return 0;
}

