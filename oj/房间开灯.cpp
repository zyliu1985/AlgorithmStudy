#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int x, y;
};
int ans = 1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool can_go[105][105], lignt[105][105], vis[105][105];
vector<node> v[105][105];
queue<node> q;
void bfs(){
	q.push({1, 1});
	lignt[1][1] = true;
	vis[1][1] = true;
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++){ // 正常走
			int nx = x + dx[i];
			int ny = y + dy[i];
			can_go[nx][ny] = true;
			if (lignt[nx][ny] && !vis[nx][ny]){
				q.push({nx, ny});
				vis[nx][ny] = true;
			}
		}
		for (int i = 0; i < v[x][y].size(); i++){ // 开灯，瞬移
			int nx = v[x][y][i].x;
			int ny = v[x][y][i].y;
			if (!lignt[nx][ny]){
				lignt[nx][ny] = true;
				ans++;
			}
			if (!vis[nx][ny] && can_go[nx][ny]){
				q.push({nx, ny});
				vis[nx][ny] = true;
			}
		}
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v[x][y].push_back({a, b});
	}
	bfs();
	cout << ans << endl;
	return 0;
}