#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[200005], w[200005];
long long dp[200005];
void dfs1(int x, int fa){
	if (v[x].size() == 1 && x != 1) dp[x] = 1e18;
	else dp[x] = 0;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dfs1(v[x][i], x);
		dp[x] += min(dp[v[x][i]], w[x][i] * 1ll);
	}
}
void dfs2(int x, int fa, int l){
	if (x > 1){
		if (v[x].size() == 1){
			if (v[fa].size() == 1) dp[x] += l;
			else dp[x] = min(dp[fa] - l, l * 1ll);
		} else {
			if (v[fa].size() == 1) dp[x] += l;
			else dp[x] += min(dp[fa] - min(dp[x], l * 1ll), l * 1ll);
		}
	}
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dfs2(v[x][i], x, w[x][i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			v[i].clear(), w[i].clear();
		for (int i = 1; i < n; i++){
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back(b);
			v[b].push_back(a);
			w[a].push_back(c);
			w[b].push_back(c);
		}
//		if (n == 1){
//			cout << 0 << '\n';
//			continue;
//		} 
		dfs1(1, 0);
		dfs2(1, 0, 0);
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, dp[i]);
		cout << ans << '\n'; 
	}
	return 0;
}

