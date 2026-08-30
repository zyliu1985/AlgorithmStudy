#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int mod = 1e9 + 7;
stack<int> st;
vector<int> v[500005], g[500005];
int cur, colur;
int dfn[500005], low[500005], col[500005];
int sz[500005], val[500005], bas[500005], pow2[500005];
int f[500005];
long long dp[500005][2];
void tarjan(int x, int fa){
	dfn[x] = low[x] = ++cur;
	st.push(x);
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		if (!dfn[v[x][i]]){
			tarjan(v[x][i], x);
			low[x] = min(low[x], low[v[x][i]]);
		} else {
			low[x] = min(low[x], dfn[v[x][i]]);
		}
	}
	if (dfn[x] == low[x]){
		++colur;
		while (!st.empty() && st.top() != x){
			col[st.top()] = colur;
			st.pop();
		}
		col[st.top()] = colur;
		st.pop();
	}
}
void dfs(int x, int fa){
	f[x] = fa;
	sz[x] = 1;
	dp[x][0] = bas[x];
	dp[x][1] = bas[x] * 1ll * val[x] % mod;
	for (int i = 0; i < g[x].size(); i++){
		if (g[x][i] == fa) continue;
		dfs(g[x][i], x);
		sz[x] += sz[g[x][i]];
		dp[x][0] = dp[x][0] * 2 * dp[g[x][i]][0] % mod;
		dp[x][1] = dp[x][1] * ((dp[g[x][i]][1] + 2*dp[g[x][i]][0]) % mod) % mod;
	}
	dp[x][1] = (dp[x][1] - dp[x][0] + mod) % mod;
//	cout << "x: " << x << ",0: " << dp[x][0] << '\n';
//	cout << "x: " << x << ",1: " << dp[x][1] << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	tarjan(1, 0);
//	for (int i = 1; i <= n; i++)
//		cout << col[i] << ' ';
//	cout << '\n';
	for (int i = 1; i <= colur; i++)
		val[i] = bas[i] = 1;
	for (int i = 1; i <= n; i++){
		val[col[i]] = val[col[i]] * 2 % mod;
		for (int j = 0; j < v[i].size(); j++)
			if (col[i] == col[v[i][j]]){
				if (i < v[i][j]) bas[col[i]] = (bas[col[i]] * 2) % mod;
			} else {
				g[col[i]].push_back(col[v[i][j]]);
			}
	}
	pow2[0] = 1;
	for (int i = 1; i <= colur; i++)
		pow2[i] = pow2[i-1] * 2 % mod;
	dfs(1, 0);
	long long ans = dp[1][1];
	for (int i = 2; i <= colur; i++)
		ans = (ans + dp[i][1] * (pow2[sz[1] - sz[i]] - pow2[sz[1] - sz[i] - g[f[i]].size()])) % mod;
	cout << ans << '\n';
	return 0;
}

