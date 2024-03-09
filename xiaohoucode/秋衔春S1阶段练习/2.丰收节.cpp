#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool vis[1005];
int box[1005], flag[1005];
vector<int> v[1005];
void dfs(int now, int x){
	vis[now] = true;
	box[now] += x;
	for (int i = 0; i < v[now].size(); i++)
		if (!vis[v[now][i]]) dfs(v[now][i], x);
}
int main(){
	int k, n, m;
	cin >> k >> n >> m;
	for (int i = 1; i <= k; i++){
		int x;
		cin >> x;
		flag[x]++;
	}
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	for (int i = 1; i <= n; i++){
		if (flag[i]){
			dfs(i, flag[i]);
			memset(vis, false, sizeof(vis));
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (box[i] >= k) cnt++;
	}
	cout << cnt << endl;
	return 0;
}