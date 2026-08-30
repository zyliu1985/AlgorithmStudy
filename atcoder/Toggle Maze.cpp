#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char mp[505][505];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct node{
	bool op;
	int x, y;
};
queue<node> q;
int dis[2][505][505];
bool vis[2][505][505];
int h, w;
bool in(int x, int y){
	return 1 <= x && x <= h && 1 <= y && y <= w;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int sx, sy;
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++){
			cin >> mp[i][j];
			if (mp[i][j] == 'S'){
				sx = i, sy = j;
			}
		}
	q.push({0, sx, sy});
	dis[0][sx][sy] = 0;
	vis[0][sx][sy] = true;
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		bool op = q.front().op;
		int d = dis[op][x][y];
		q.pop();
		if (mp[x][y] == 'G'){
			cout << d << '\n';
			return 0;
		} else if (mp[x][y] == '?'){
			op ^= 1;
		}
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!in(nx, ny)) continue;
			if (mp[nx][ny] == '#') continue;
			if (((mp[nx][ny] == 'x') ^ op) && (mp[nx][ny] == 'o' || mp[nx][ny] == 'x')) continue;
			if (vis[op][nx][ny]) continue;
			q.push({op, nx, ny});
			dis[op][nx][ny] = d + 1;
			vis[op][nx][ny] = true;
		}
	}
	cout << -1 << '\n';
	return 0;
}

