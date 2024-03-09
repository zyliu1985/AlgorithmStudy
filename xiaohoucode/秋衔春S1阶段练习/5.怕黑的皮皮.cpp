#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct node{
	int x, y;
};
int n, m;
bool light[105][105], can_go[105][105], vis[105][105];
vector<node> v[105][105];
queue<node> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
void bfs(){
	light[1][1] = true;
	can_go[1][1] = true;
	can_go[1][2] = true;
	can_go[2][1] = true;
	vis[1][1] = true;
	q.push({1, 1});
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		// cout << x << ' ' << y << endl;
		for (int i = 0; i < v[x][y].size(); i++){ // 开灯，瞬移
			light[v[x][y][i].x][v[x][y][i].y] = true;
			if (can_go[v[x][y][i].x][v[x][y][i].y] && !vis[v[x][y][i].x][v[x][y][i].y]){
				q.push({v[x][y][i].x, v[x][y][i].y});
				vis[v[x][y][i].x][v[x][y][i].y] = true;
			}
		}
		for (int i = 0; i < 4; i++){ // 直接走
			int xx = dx[i] + x;
			int yy = dy[i] + y;
			if (in(xx, yy) && !vis[xx][yy]){
				can_go[xx][yy] = true; // 可瞬移点
				if (light[xx][yy]){
					q.push({xx, yy});
					vis[xx][yy] = true;
				}
			}
		}
	}
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[a][b].push_back({c, d});
	}
	bfs();
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans += light[i][j];
	cout << ans << endl;
	return 0;
}