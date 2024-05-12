#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[1005][1005], dis[1005][1005], n, m, vis[1005][1005];
struct node{
	int x, y;
};
queue<node> q;
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
int bfs(int stx, int sty){
	dis[stx][sty] = 0;
	vis[stx][sty] = true;
	q.push({stx, sty});
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		if (x == n && y == m) return dis[x][y];
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i] * a[x][y];
			int ny = y + dy[i] * a[x][y];
			if (in(nx, ny) && !vis[nx][ny]){
				dis[nx][ny] = dis[x][y] + 1;
				vis[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
	return -1;
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	int ans = bfs(1, 1);
	if (ans == -1) cout << "No Solution" << endl;
	else cout << ans << endl;
	return 0;
}