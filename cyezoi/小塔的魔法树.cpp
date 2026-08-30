#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int w[5005], dfn[5005], fdfn[5005], mxdfn[5005], cur;
long long dp[5005][5005];
vector<int> v[5005];
void dfs(int x, int fa){
//	cout << cur << '\n';
	cur++;
	dfn[x] = cur;
	fdfn[cur] = x;
	mxdfn[dfn[x]] = cur;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			dfs(v[x][i], x);
			mxdfn[dfn[x]] = max(mxdfn[dfn[x]], mxdfn[dfn[v[x][i]]]);
		}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		cur = 0;
		memset(dp, 0, sizeof(dp));
//		memset(dfn, 0, sizeof(dfn));
//		memset(fdfn, 0, sizeof(fdfn));
//		memset(mxdfn, 0, sizeof(mxdfn));
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			v[i].clear();
		for (int i = 1; i <= n; i++)
			cin >> w[i];
		for (int i = 1; i < n; i++){
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(1, 0);
		dp[1][0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++){
				if (i != 1) dp[mxdfn[i] + 1][j] += dp[i][j];
				if (j + w[fdfn[i]] <= m) dp[i + 1][j + w[fdfn[i]]] += dp[i][j];
			}
//		for (int i = 1; i <= n+1; i++){
//			for (int j = 0; j <= m; j++)
//				cout << dp[i][j] << ' ';
//			cout << '\n';
//		}
		long long ans = 0;
		for (int i = 0; i <= m; i++)
			ans += dp[n+1][i];
		cout << ans << '\n';
	}
	return 0;
}



