#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cur;
vector<int> v[50005];
int dfn[50005], low[50005], rnxt[50005];
int dp[50005][2];
bool vis[50005];
void init(int x){
	dfn[x] = low[x] = ++cur;
	for (int i = 0; i < v[x].size(); i++)
		if (!dfn[v[x][i]]){
			init(v[x][i]);
			low[x] = min(low[x], low[v[x][i]]);
			if (low[v[x][i]] < dfn[x]) rnxt[x] = v[x][i];
		} else low[x] = min(low[x], dfn[v[x][i]]);
}
int temp[50005];
void solve(int x){
	dp[x][0] = 0, dp[x][1] = 1;
	vis[x] = true;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == rnxt[x]) continue;
		if (vis[v[x][i]]) continue;
		solve(v[x][i]);
		if (low[v[x][i]] > dfn[x]){
			dp[x][0] += max(dp[v[x][i]][0], dp[v[x][i]][1]);
			dp[x][1] += dp[v[x][i]][0];
		} else {
			cout << "ring\n";
			int now = v[x][i], len = 1;
			temp[1] = x;
			while (now) temp[++len] = now, now = rnxt[now];
			int now0 = 0, now1 = 1;
			for (int i = 2; i <= len; i++){
				int lst = now1;
				now1 = dp[temp[i]][1] + now0;
				now0 = dp[temp[i]][0] + max(now0, lst); 
			}
			dp[x][0] += max(now0, now1);
			now0 = dp[temp[2]][0], now1 = dp[temp[2]][1];
			for (int i = 3; i <= len; i++){
				int lst = now1;
				now1 = dp[temp[i]][1] + now0;
				now0 = dp[temp[i]][0] + max(now0, lst); 
			}
			dp[x][1] += now1;
		}
	}
	if (rnxt[x]) solve(rnxt[x]);
	cout << x << ':' << dp[x][0] << ',' << dp[x][1] << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	init(1);
	solve(1);
	cout << max(dp[1][0], dp[1][1]) << '\n';
	return 0;
}

