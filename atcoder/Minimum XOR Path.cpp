#include <iostream>
#include <algorithm>
#include <cstring> 
#include <vector>
#include <queue>
using namespace std;

int n;
long long ans = 1e18;
bool vis[15];
vector<long long> v[15], w[15];
void dfs(int x, long long sum){
	if (x == n){
		ans = min(ans, sum);
		return;
	}
	vis[x] = true;
	for (int i = 0; i < v[x].size(); i++)
		if (!vis[v[x][i]]){
			dfs(v[x][i], sum ^ w[x][i]);
		}
	vis[x] = false;
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		long long a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[b].push_back(a);
		w[a].push_back(c);
		w[b].push_back(c);
	}
	dfs(1, 0);
	cout << ans << '\n';
	return 0;
}



