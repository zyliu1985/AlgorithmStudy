#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
bool mp[35][35], invis[35][35];
long long indis[35][35][35][35];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct node{
	int x, y;
};
queue<node> q;
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
void bfs(int sx, int sy){
	memset(invis, 0, sizeof(invis));
	indis[sx][sy][sx][sy] = 0;
	q.push({sx, sy});
	invis[sx][sy] = true;
	while (!q.empty()){
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny) && !invis[nx][ny] && mp[nx][ny]){
				indis[sx][sy][nx][ny] = indis[sx][sy][x][y] + 1;
				q.push({nx, ny});
				invis[nx][ny] = true;
			}
		}
	}
}
void init(){
	memset(indis, 0x3f, sizeof(indis));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			if (mp[i][j]) bfs(i, j);
		}
}

struct qnode{
	int x, y, dir;
	long long d;
	friend bool operator < (const qnode x, const qnode y){
		return x.d > y.d;
	}
};
priority_queue<qnode> pq;
long long dis[35][35][4];
bool vis[35][35][4];
void update(int nx, int ny, int ndir, int x, int y, int dir, long long w){
	if (dis[nx][ny][ndir] > dis[x][y][dir] + w){
		dis[nx][ny][ndir] = dis[x][y][dir] + w;
		pq.push({nx, ny, ndir, dis[nx][ny][ndir]});
	}
}
void solve(int ex, int ey, int sx, int sy, int tx, int ty){
	for (int i = 0; i < 4; i++){
		dis[sx][sy][i] = indis[ex][ey][sx + dx[i]][sy + dy[i]];
		pq.push({sx, sy, i, dis[sx][sy][i]});
	}
	while (!pq.empty()){
		int x = pq.top().x, y = pq.top().y, dir = pq.top().dir;
		cout << x << ',' << y << ',' << dir << ':' << dis[x][y][dir] << '\n';
		pq.pop();
		if (vis[x][y][dir]) continue;
		vis[x][y][dir] = true;
		// ½»»»
		update(x + dx[dir], y + dy[dir], (dir + 2) % 4, x, y, dir, 1);
		// »»Ïò
		for (int i = 0; i < 4; i++){
			if (i == dir) continue;
			update(x, y, i, x, y, dir, indis[x + dx[dir]][y + dy[dir]][x + dx[i]][y + dy[i]]);
		}
	}
	long long ans = min(min(dis[tx][ty][0], dis[tx][ty][1]), min(dis[tx][ty][2], dis[tx][ty][3]));
	if (ans > 1e12) cout << -1 << '\n';
	else cout << ans << '\n';
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	int q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];
	init();
	while (q--){
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		int ex, ey, sx, sy, tx, ty;
		cin >> ex >> ey >> sx >> sy >> tx >> ty;
		solve(ex, ey, sx, sy, tx, ty);
	}
	return 0;
}

