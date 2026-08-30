#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct sqr{
	int n, m;
	long long val[2][2];
	void clear(){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				val[i][j] = 1e18;
	}
	friend sqr operator * (const sqr x, const sqr y){
		sqr z;
		z.n = x.n, z.m = y.m;
		z.clear();
		if (x.m != y.n) exit(9);
		for (int i = 0; i < x.n; i++)
			for (int j = 0; j < y.m; j++)
				for (int k = 0; k < x.m; k++)
					z.val[i][j] = min(z.val[i][j], x.val[i][k] + y.val[k][j]);
		return z;
	}
	void print(){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				cout << val[i][j] << ' ';
			cout << '\n';
		}
	}
} base[100005][20]; 
int n, m;
int p[100005];
long long dp[100005][2];
int f[100005][20], d[100005];
vector<int> v[100005];

// 处理 dp[x],f[x][0],d[x],base[x][0] 
void dfs(int x){
	dp[x][0] = 0, dp[x][1] = p[x];
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == f[x][0]) continue;
		f[v[x][i]][0] = x;
		d[v[x][i]] = d[x] + 1;
		dfs(v[x][i]);
		dp[x][0] += dp[v[x][i]][1];
		dp[x][1] += min(dp[v[x][i]][0], dp[v[x][i]][1]);
	}
	long long z = min(dp[x][0], dp[x][1]);
	base[x][0].n = base[x][0].m = 2;
	base[x][0].clear();
	base[x][0].val[0][1] = dp[x][0] - z;
	base[x][0].val[1][0] = 0;
	base[x][0].val[1][1] = dp[x][1] - z;
}

// 处理倍增下的 f[x],base[x]
void init(){
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= n; j++){
			f[j][i] = f[f[j][i-1]][i-1];
			if (f[j][i]) base[j][i] = base[j][i-1] * base[f[j][i-1]][i-1];
		}
} 

// 计算num次转移后的矩阵 
sqr calc(sqr org, int x, int num){
	int now = 0;
	while (num > 0){
		if (num & 1){
			org = org * base[x][now];
			x = f[x][now];
		}
		num >>= 1;
		now++;
	}
	return org;
} 

// 最近公共祖先 
int lca(int x, int y){
	if (d[x] < d[y]) swap(x, y);
	int dd = d[x] - d[y];
	int now = 0;
	while (dd > 0){
		if (dd & 1){
			x = f[x][now];
		}
		dd >>= 1;
		now++;
	}
	for (int i = 19; i >= 0; i--)
		if (f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	if (x != y) x = f[x][0], y = f[y][0];
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string type;
	cin >> n >> m >> type;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	init();
	while (m--){
		int a, b;
		bool x, y;
		cin >> a >> x >> b >> y;
		sqr adda, addb;
		adda.n = addb.n = 1;
		adda.m = addb.m = 2;
		adda.clear(), addb.clear();
		adda.val[0][x] = 0;
		addb.val[0][y] = 0;
		int lm = lca(a, b);
		adda = calc(adda, a, d[a] - d[lm]);
		addb = calc(addb, b, d[b] - d[lm]);
//		cout << lm << ":\n";
//		adda.print(), cout << "---------------\n"; addb.print(), cout << "---------------\n";
		adda.val[0][0] += addb.val[0][0];
		adda.val[0][1] += addb.val[0][1];
		adda = calc(adda, lm, d[lm]);
		long long ans = min(dp[1][0] + adda.val[0][0], dp[1][1] + adda.val[0][1]);
		if (ans >= 1e17) cout << -1 << '\n';
		else cout << ans << '\n';
	}
	return 0;
}

