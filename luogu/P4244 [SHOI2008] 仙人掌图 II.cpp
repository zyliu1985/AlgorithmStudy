#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

vector<int> v[50005];
int cur;
int dfn[50005], low[50005], rnxt[50005];
int dp[50005], ans;
void init(int x, int fa){
	dfn[x] = low[x] = ++cur;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		if (!dfn[v[x][i]]){
			init(v[x][i], x);
			low[x] = min(low[x], low[v[x][i]]);
			if (low[v[x][i]] < dfn[x]) rnxt[x] = v[x][i];
		} else {
			low[x] = min(low[x], dfn[v[x][i]]);
		}
	}
}
int temp[100005];
deque<pair<int, int> > q;
bool vis[100005];
void solve(int x){
	vis[x] = true;
//	cout << "enter " << x << '\n';
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == rnxt[x]) continue;
		if (!vis[v[x][i]]){
			solve(v[x][i]);
			if (low[v[x][i]] > dfn[x]){
				ans = max(ans, dp[x] + dp[v[x][i]] + 1);
				dp[x] = max(dp[x], dp[v[x][i]] + 1);
			} else if (low[v[x][i]] == dfn[x]) {
				int now = v[x][i], len = 1;
				temp[1] = x;
				while (now) temp[++len] = now, now = rnxt[now];
//				cout << "update:" << '\n';
//				cout << "len = " << len << '\n';
				for (int i = len+1; i <= len*2; i++)
					temp[i] = temp[i - len];
				q.clear();
				for (int i = 1; i <= len*2; i++){
					while (!q.empty() && q.front().second < i - len / 2) q.pop_front();
					if (!q.empty()) ans = max(ans, dp[temp[i]] + i + q.front().first);
					while (!q.empty() && q.back().first <= dp[temp[i]] - i) q.pop_back();
//									cout << "update ans with " << dp[temp[i]] + i + q.front().first << "  now ans is " << ans << '\n',
//									cout << "update id: " << temp[q.front().second] << ',' << temp[i] << '\n';
					q.push_back(make_pair(dp[temp[i]] - i, i));
				}
				for (int i = 2; i <= len; i++){
//					cout << "updated with " << dp[temp[i]] + min(i-1, len-i+1) << '\n';
					dp[x] = max(dp[x], dp[temp[i]] + min(i-1, len-i+1));
				}
				// ans = max(ans, i - j + f[i] + f[j])
			} else {
				while (1);
			}
		}
	}
	if (rnxt[x]) solve(rnxt[x]);
//	cout << "exit " << x << ", with dp = " << dp[x] << '\n';
}
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int k, lst;
		cin >> k >> lst;
		for (int j = 2; j <= k; j++){
			int x;
			cin >> x;
			v[x].push_back(lst);
			v[lst].push_back(x);
			lst = x;
		}
	}
	init(1, 0);
//	for (int i = 1; i <= n; i++)
//		cout << rnxt[i] << ' ';
//	cout << '\n';
	solve(1);
	cout << ans << '\n';
	return 0;
}
