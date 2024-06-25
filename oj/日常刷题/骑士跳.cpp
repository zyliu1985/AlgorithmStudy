#include <iostream>
#include <queue>
using namespace std;

struct node{
	int x, y;
};
int dis[10][10];
int x1, y1, x2, y2;
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool vis[10][10];
queue<node> q;
bool in(int x, int y){
	return 1 <= x && x <= 8 && 1 <= y && y <= 8;
}
int bfs(){
	q.push({x1, y1});
	dis[x1][y1] = 0;
	vis[x1][y1] = true;
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		if (x == x2 && y == y2) return dis[x][y];
		for (int i = 0; i < 8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny) && !vis[nx][ny]){
				q.push({nx, ny});
				dis[nx][ny] = dis[x][y] + 1;
				vis[nx][ny] = true;
			}
		}
	}
	return -1;
}
int main(){
	cin >> x1 >> y1 >> x2 >> y2;
	cout << bfs() << endl;
	return 0;
}