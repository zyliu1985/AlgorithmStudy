#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[100005], w[100005];
int sz[100005], fw[100005]; 
long long dp[100005];
void dfs1(int x, int fa){
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa){
			fw[x] = w[x][i];
			continue; 
		}
		dfs1(v[x][i], x);
		dp[x] += dp[v[x][i]] + w[x][i] * 1ll * sz[v[x][i]];
		sz[x] += sz[v[x][i]];
	}
}
void dfs2(int x, int fa, int l){
	if (x > 1){
		dp[x] += dp[fa] - dp[x] - l * 1ll * sz[x] + fw[x] * 1ll * (sz[1] - sz[x]);
	}
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dfs2(v[x][i], x, w[x][i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		v[a].push_back(b);
		v[b].push_back(a);
		w[a].push_back(x);
		w[b].push_back(y);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	long long ans = 1e18;
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[i]);
	cout << ans << '\n';
	return 0;
}

