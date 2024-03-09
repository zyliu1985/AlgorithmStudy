#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

bool vis[10005];
int dis[10005];
vector<int> v[10005];
queue<int> q;
void dfs(int now){
	vis[now] = true;
	if (v[now].size() == 0) return;
	for (int i = 0; i < v[now].size(); i++)
		if (!vis[v[now][i]]) dfs(v[now][i]);
}
int bfs(){
	q.push(1);
	vis[1] = true;
	dis[1] = 1;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		if (v[x].size() == 0) return dis[x];
		for (int i = 0; i < v[x].size(); i++)
			if (!vis[v[x][i]]){
				q.push(v[x][i]);
				vis[v[x][i]] = true;
				dis[v[x][i]] = dis[x] + 1;
			}
	}
	return -1;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int m;
		cin >> m;
		for (int j = 1; j <= m; j++){
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}
	dfs(1);
	bool flag = true;
	for (int i = 1; i <= n; i++)
		if (!vis[i]){
			flag = false;
			cout << 'N' << endl;
			break;
		}
	if (flag) cout << 'Y' << endl;
	memset(vis, false, sizeof(vis));
	cout << bfs() << endl;
	return 0;
}