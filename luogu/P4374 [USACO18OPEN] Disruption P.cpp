#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[50005], id[50005];
int n, m;
int fa[50005][17], depth[50005], faid[50005], mark[50005][17];
int ans[50005];
void dfs(int x){
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa[x][0]) continue;
		fa[v[x][i]][0] = x;
		faid[v[x][i]] = id[x][i];
		depth[v[x][i]] = depth[x] + 1;
		dfs(v[x][i]); 
	}
}
void init(){
	for (int i = 1; i <= 16; i++)
		for (int j = 1; j <= n; j++)
			fa[j][i] = fa[fa[j][i-1]][i-1];
}
void lca(int x, int y, int w){
	if (depth[x] < depth[y]) swap(x, y);
	int dd = depth[x] - depth[y];
	int now = 0;
	while (dd > 0){
		if (dd & 1){
			mark[x][now] = min(mark[x][now], w);
			x = fa[x][now];
		}
		now++;
		dd >>= 1;
	}
	for (int i = 16; i >= 0; i--)
		if (fa[x][i] != fa[y][i]){
			mark[x][i] = min(mark[x][i], w);
			mark[y][i] = min(mark[y][i], w);
			x = fa[x][i];
			y = fa[y][i];
		}
	if (x != y){
		mark[x][0] = min(mark[x][0], w);
		mark[y][0] = min(mark[y][0], w);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		id[a].push_back(i);
		id[b].push_back(i);
	}
	dfs(1);
	init();
	memset(mark, 0x3f, sizeof(mark));
	for (int i = 1; i <= m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		lca(a, b, w);
	}
	for (int i = 16; i >= 1; i--)
		for (int j = 1; j <= n; j++){
			mark[j][i-1] = min(mark[j][i-1], mark[j][i]);
			mark[fa[j][i-1]][i-1] = min(mark[fa[j][i-1]][i-1], mark[j][i]);
		}
	for (int i = 2; i <= n; i++)
		ans[faid[i]] = mark[i][0];
	for (int i = 1; i < n; i++)
		if (ans[i] <= 1e9){
			cout << ans[i] << '\n';
		} else {
			cout << -1 << '\n';
		}
	return 0;
}

