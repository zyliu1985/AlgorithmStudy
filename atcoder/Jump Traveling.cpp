#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dis[200005], k;
bool vis[200005];
vector<int> v[200005], g[200005];
void dfs(int x, int fa, int ds, int ffa){
	if (ds == k){
		g[ffa].push_back(x);
		g[x].push_back(ffa); 
		vis[x] = true;
		return;
	}
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			dfs(v[x][i], x, ds + 1, ffa);
		}
}
void solve(int x){
//	cout << x << '\n';
	for (int i = 0; i < g[x].size(); i++)
		if (g[x][i] != 1 && !dis[g[x][i]]){
			dis[g[x][i]] = dis[x] + 1;
			solve(g[x][i]);
		}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
		int n;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			v[i].clear(), g[i].clear(), dis[i] = 0, vis[i] = false;
		for (int i = 1; i < n; i++){
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i]) dfs(i, 0, 0, i);
		solve(1); 
		for (int i = 2; i <= n; i++)
			if (dis[i] == 0) cout << -1 << ' ';
			else cout << dis[i] << ' ';
		cout << '\n';
	}
	return 0;
}



