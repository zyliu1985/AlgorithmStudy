#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[1005], ans;
int n, m, x, y;
bool flag, vis[1005];
void dfs(int now){
	ans.push_back(now);
	vis[now] = true;
	if (now == y){
		flag = true;
		return;
	}
	for (int i = 0; i < v[now].size(); i++){
		if (!vis[v[now][i]]) dfs(v[now][i]);
		if (flag) return;
	}
	ans.pop_back();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m >> x >> y;
		for (int i = 1; i <= n; i++)
			v[i].clear(), vis[i] = false;
		ans.clear();
		flag = false;
		for (int i = 1; i <= m; i++){
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
			sort(v[i].begin(), v[i].end());
		dfs(x);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}

