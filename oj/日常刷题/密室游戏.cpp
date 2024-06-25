#include <iostream>
#include <queue>
using namespace std;

char c[35][35];
int stx, sty, edx, edy, cx[2][3], cy[2][3];
struct node{
	int x, y;
};
int n, m;
queue<node> q;
bool vis[35][35];
int dis[35][35];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
int bfs(){
	q.push({stx, sty});
	vis[stx][sty] = true;
	dis[stx][sty] = 0;
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		if (x == edx && y == edy) return dis[x][y];
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (in(nx, ny) && !vis[nx][ny] && c[nx][ny] != '#'){
				q.push({nx, ny});
				vis[nx][ny] = true;
				dis[nx][ny] = dis[x][y] + 1;
			}
		}
		if (c[x][y] == 'a' || c[x][y] == 'b' || c[x][y] == 'c'){
			int nx, ny;
			if (cx[0][int(c[x][y]-'a')] == x && cy[0][int(c[x][y]-'a')] == y){
				nx = cx[1][int(c[x][y]-'a')];
				ny = cy[1][int(c[x][y]-'a')];
			} else {
				nx = cx[0][int(c[x][y]-'a')];
				ny = cy[0][int(c[x][y]-'a')];
			}
			if (!vis[nx][ny]){
				q.push({nx, ny});
				vis[nx][ny] = true;
				dis[nx][ny] = dis[x][y] + 1;
			}
		}
	}
	return -1;
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> c[i][j];
			if (c[i][j] == '$'){ // 判断起点
				stx = i;
				sty = j;
			} else if (c[i][j] == '@'){ // 判断终点
				edx = i;
				edy = j;
			} else if (c[i][j] == 'a' || c[i][j] == 'b' || c[i][j] == 'c') // 判断传送门
				if (cx[0][int(c[i][j] - 'a')] != 0){
					cx[1][int(c[i][j] - 'a')] = i;
					cy[1][int(c[i][j] - 'a')] = j;
				} else {
					cx[0][int(c[i][j] - 'a')] = i;
					cy[0][int(c[i][j] - 'a')] = j;
				}
		}
	cout << bfs() << endl;
	return 0;
}