#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[300005];
struct node{
	int s, lc;
	int type;
};
vector<node> rev[300005];
int w[300005];
// 0: w[x] + d[x]
// 1: w[x] - d[x] + n
int box0[300005], box1[600005], ans[300005];
int fa[300005][20], d[300005];
int n, m;
void init1(int x){
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa[x][0]) continue;
		fa[v[x][i]][0] = x;
		d[v[x][i]] = d[x] + 1;
		init1(v[x][i]);
	}
}
void init2(){
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= n; j++)
			fa[j][i] = fa[fa[j][i-1]][i-1];
}
int lca(int x, int y){
	if (d[x] < d[y]) swap(x, y);
	int mina = d[x] - d[y];
	int now = 0;
	while (mina > 0){
		if (mina & 1) x = fa[x][now];
		now++;
		mina >>= 1;
	}
	for (int i = 19; i >= 0; i--)
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	if (x != y){
		x = fa[x][0];
		y = fa[y][0];
	}
	return x;
}
void dfs(int x){
	int pre = 0;
	if (w[x] + d[x] <= n) pre += box0[w[x] + d[x]];
	pre += box1[w[x] - d[x] + n];
	
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa[x][0])
			dfs(v[x][i]);
	
	for (int i = 0; i < rev[x].size(); i++){
		if (rev[x][i].type == 1){
			box0[d[rev[x][i].s]]++;
		} else if (rev[x][i].type == 2){
			box1[d[rev[x][i].s] - 2 * d[rev[x][i].lc] + n]++;
		}
	}
	if (w[x] + d[x] <= n) ans[x] += box0[w[x] + d[x]];
	ans[x] += box1[w[x] - d[x] + n];
	ans[x] -= pre;
	
	for (int i = 0; i < rev[x].size(); i++){
		if (!rev[x][i].type){
			box0[d[rev[x][i].s]]--;
			box1[d[rev[x][i].s] - 2 * d[rev[x][i].lc] + n]--;
			if (d[rev[x][i].s] - d[x] == w[x]) ans[x]--;
		}
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
	}
	init1(1);
	init2();
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= m; i++){
		int s, t;
		cin >> s >> t;
		int lc = lca(s, t);
		rev[lc].push_back({s, lc, 0});
		rev[s].push_back({s, lc, 1});
		rev[t].push_back({s, lc, 2});
//		box0[d[s]]++;
//		box1[d[s] - 2 * d[lc] + n]++;
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}

