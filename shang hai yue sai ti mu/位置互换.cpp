#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char mp[45][45];
int n, m, sx1, sx2, sy1, sy2;
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {1, 0, -1, 0, 0};
struct node{
	int x1, y1, x2, y2;
};
queue<node> q;
int dis[45][45][45][45], vis[45][45][45][45];
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
int bfs(int x1, int y1, int x2, int y2){
	memset(dis, 0x3f, sizeof(dis));
	dis[x1][y1][x2][y2] = 0;
	vis[x1][y1][x2][y2] = true;
	q.push({x1, y1, x2, y2});
	while (!q.empty()){
		node x = q.front();
//		cout << f[x.x1][x.y1][x.x2][x.y2].x1 << ' ' << f[x.x1][x.y1][x.x2][x.y2].y1 << ' ' << f[x.x1][x.y1][x.x2][x.y2].x2 << ' ' << f[x.x1][x.y1][x.x2][x.y2].y2 << "->";
//		cout << x.x1 << ' ' << x.y1 << ' ' << x.x2 << ' ' << x.y2 << endl;
		q.pop();
		if (x.x1 == sx2 && x.y1 == sy2 && x.x2 == sx1 && x.y2 == sy1) return dis[x.x1][x.y1][x.x2][x.y2];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++){
				int nx1 = x.x1 + dx[i];
				int ny1 = x.y1 + dy[i];
				int nx2 = x.x2 + dx[j];
				int ny2 = x.y2 + dy[j];
				if (!in(nx1, ny1) || !in(nx2, ny2)) continue;
				if (mp[nx1][ny1] == '#' || mp[nx2][ny2] == '#') continue;
				if (vis[nx1][ny1][nx2][ny2]) continue;
				if ((nx1 == nx2 || nx1 == x.x2) && (ny1 == ny2 || ny1 == x.y2)) continue;
				if (nx2 == x.x1 && ny2 == x.y1) continue;
				dis[nx1][ny1][nx2][ny2] = dis[x.x1][x.y1][x.x2][x.y2] + 1;
				vis[nx1][ny1][nx2][ny2] = true;
				q.push({nx1, ny1, nx2, ny2});
//				f[nx1][ny1][nx2][ny2].x1 = x.x1;
//				f[nx1][ny1][nx2][ny2].y1 = x.y1;
//				f[nx1][ny1][nx2][ny2].x2 = x.x2;
//				f[nx1][ny1][nx2][ny2].y2 = x.y2;
			}
	}
	return -1;
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> mp[i][j];
			if (mp[i][j] == '1'){
				sx1 = i;
				sy1 = j;
			} else if (mp[i][j] == '2'){
				sx2 = i;
				sy2 = j;
			}
		}
	int ans = bfs(sx1, sy1, sx2, sy2);
	if (ans == -1) cout << "No Solution" << endl;
	else cout << ans << endl;
	return 0;
}