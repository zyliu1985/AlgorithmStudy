#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long inf = 1e18;
struct sqr{
	int n, m;
	long long val[4][4];
	void clear(){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				val[i][j] = inf; 
	}
	friend sqr operator * (const sqr x, const sqr y){
		sqr z;
		z.n = x.n, z.m = y.m;
		z.clear();
		if (x.m != y.n) return z;
		for (int i = 1; i <= x.n; i++)
			for (int j = 1; j <= y.m; j++)
				for (int k = 1; k <= x.m; k++)
					z.val[i][j] = min(z.val[i][j], x.val[i][k] + y.val[k][j]);
		return z;
	}
	void print(){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++)
				cout << val[i][j] << ' ';
			cout << '\n';
		}
	}
};
int n, q, k;
long long w[200005], wson[200005];
int fa[200005][20];
int d[200005];
sqr base1[200005][18];
sqr base2[200005][18];
vector<int> v[200005];
void init1(int x){
	base1[x][0].n = base1[x][0].m = 3;
	base1[x][0].clear();
	base1[x][0].val[1][1] = w[fa[x][0]];
	base1[x][0].val[2][2] = 0;
	base1[x][0].val[3][3] = 0;
	
	base2[x][0].n = base2[x][0].m = 3;
	base2[x][0].clear();
	base2[x][0].val[1][1] = w[x];
	base2[x][0].val[2][2] = 0;
	base2[x][0].val[3][3] = 0;
}
void init2(int x){
	base1[x][0].n = base1[x][0].m = 3;
	base1[x][0].clear();
	base1[x][0].val[1][1] = w[fa[x][0]];
	base1[x][0].val[2][1] = w[fa[x][0]];
	base1[x][0].val[1][2] = 0;
	base1[x][0].val[3][3] = 0;
	
	base2[x][0].n = base2[x][0].m = 3;
	base2[x][0].clear();
	base2[x][0].val[1][1] = w[x];
	base2[x][0].val[2][1] = w[x];
	base2[x][0].val[1][2] = 0;
	base2[x][0].val[3][3] = 0;
}
void init3(int x){
	base1[x][0].n = base1[x][0].m = 3;
	base1[x][0].clear();
	base1[x][0].val[1][1] = w[fa[x][0]];
	base1[x][0].val[2][1] = w[fa[x][0]];
	base1[x][0].val[3][1] = w[fa[x][0]];
	base1[x][0].val[1][2] = 0;
	base1[x][0].val[2][2] = wson[fa[x][0]];
	base1[x][0].val[3][2] = w[fa[x][0]] + wson[fa[x][0]];
	base1[x][0].val[2][3] = 0;
	
	base2[x][0].n = base2[x][0].m = 3;
	base2[x][0].clear();
	base2[x][0].val[1][1] = w[x];
	base2[x][0].val[2][1] = w[x];
	base2[x][0].val[3][1] = w[x];
	base2[x][0].val[1][2] = 0;
	base2[x][0].val[2][2] = wson[x];
	base2[x][0].val[3][2] = w[x] + wson[x];
	base2[x][0].val[2][3] = 0;
}
void dfs(int x){
	if (x > 1) wson[x] = w[fa[x][0]];
	else wson[x] = 1e18;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa[x][0]) continue;
		fa[v[x][i]][0] = x;
		d[v[x][i]] = d[x] + 1;
		wson[x] = min(wson[x], w[v[x][i]]);
		dfs(v[x][i]);
	}
}
void initall(){
	for (int i = 1; i <= n; i++){
		switch(k){
			case 1: init1(i); break;
			case 2: init2(i); break;
			case 3: init3(i); break;
		}
	}
	for (int i = 1; i <= 17; i++)
		for (int j = 1; j <= n; j++){
			fa[j][i] = fa[fa[j][i-1]][i-1];
			base1[j][i] = base1[j][i-1] * base1[fa[j][i-1]][i-1];
			base2[j][i] = base2[fa[j][i-1]][i-1] * base2[j][i-1];
		}
}
int lca(int x, int y){
	if (d[x] < d[y]) swap(x, y);
	int dist = d[x] - d[y];
	int now = 0;
	while (dist > 0){
		if (dist & 1)
			x = fa[x][now];
		dist >>= 1;
		now++;
	}
	for (int i = 17; i >= 0; i--)
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	if (x != y) x = fa[x][0], y = fa[y][0];
	return x;
}
long long solve(int s, int t){
	int lc = lca(s, t);
//	cout << "lc:" << lc << '\n';
	sqr ans, ans2;
	ans.n = 1;
	ans.m = 3;
	ans.clear();
	ans.val[1][1] = w[s];
	ans.val[1][2] = w[s];
	ans.val[1][3] = w[s];
	ans2.n = ans2.m = 3;
	ans2.clear();
	ans2.val[1][1] = 0;
	ans2.val[2][2] = 0;
	ans2.val[3][3] = 0;
//	while (s != lc){
////		cout << "ans:\n";
////		ans.print();
//		ans = ans * base1[s][0];
////		cout << "base1 " << s << ":\n";
////		base1[s][0].print();
//		s = fa[s][0];
//	} 
////	cout << "********************\n";
////	ans.print();
//	while (t != lc){
////		cout << "ans2:\n";
////		ans2.print();
//		ans2 = base2[t][0] * ans2;
////		cout << "base2 " << t << ":\n";
////		base2[t][0].print();
//		t = fa[t][0];
//	}
//	ans = ans * ans2;
	int dis = d[s] - d[lc];
	int now = 0;
	while (dis > 0){
		if (dis & 1){
			ans = ans * base1[s][now];
			s = fa[s][now];
		}
		dis >>= 1;
		now++;
	}
	dis = d[t] - d[lc];
	now = 0;
	while (dis > 0){
		if (dis & 1){
			ans2 = base2[t][now] * ans2;
			t = fa[t][now];
		}
		dis >>= 1;
		now++;
	}
//	cout << "********************\n";
//	ans.print();
//	ans2.print();
	ans = ans * ans2;
	return ans.val[1][1];
}
int main(){
//	freopen("transmit2.in", "r", stdin);
//	freopen("transmit.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q >> k;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	initall();
	while (q--){
		int s, t;
		cin >> s >> t;
		cout << solve(s, t) << '\n';
	}
	return 0;
}

