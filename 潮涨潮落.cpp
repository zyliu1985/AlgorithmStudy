#include <iostream>
#include <queue>
using namespace std;

struct node{
	int x, y, t, dis;
};
queue<node> q;
int h, w, c, b;
int d[105][105][25], dx[5] = {0, 0, -1, 1, 0}, dy[5] = {1, -1, 0, 0, 0};
bool vis[105][105][25];
bool in(int x, int y) {return 1 <= x && x <= h && 1 <= y && y <= w;}
int bfs(){
	// 队首入队
	q.push({1, 1, 0, 0});
	vis[1][1][0] = true;
	while (!q.empty()){
		int x, y, t, dis;
		x = q.front().x;
		y = q.front().y;
		t = q.front().t;
		q.pop();
		dis = q.front().dis;
		//cout << x << ' ' << y << ' ' << t << ' ' << dis << endl;
		if (x == h && y == w) return dis;
		
		// 遍历子节点
		for (int i = 0; i <= 4; i++){
			int nx = x + dx[i], ny = y + dy[i], nt = t%(c*2)+1;
			// 越界
			if (!in(nx, ny)) continue;
			// 重复
			if (vis[nx][ny][nt]) continue;
			// 水深不够
			if (d[nx][ny][nt] < b) continue;
			// 加入队列
			q.push({nx, ny, nt, dis+1});
		}
	}
	return -1;
}
int main(){
	cin >> h >> w >> c >> b;
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			char s;
			int p;
			cin >> d[i][j][0] >> s;
			if (s == '+') p = 1;
			else p = -1;
			for (int k = 1; k <= c*2; k++){
				d[i][j][k] = d[i][j][k-1]+p;
				if (d[i][j][k] == 0 || d[i][j][k] == c) p = -p;
			}
		}
	}
	cout << bfs() << endl;
	return 0;
}