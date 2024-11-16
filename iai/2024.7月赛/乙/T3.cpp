#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
 
long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
struct node{
	int x, y;
};
queue<node> q;
int dis[5005][5005], a, b, c;
bool vis[5005][5005];
void bfs(){
	dis[0][0] = 0;
	vis[0][0] = true;
	q.push(node{0, 0});
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = c - x - y;
		q.pop();
		int nx, ny;
		// x to y
		if (x + y > b){nx = x + y - b; ny = b;} else {nx = 0; ny = x + y;}
		if (c - nx - ny >= 0 && !vis[nx][ny]){
			dis[nx][ny] = dis[x][y] + 1;
			vis[nx][ny] = true;
			q.push(node{nx, ny});
		}
		// x to z
		if (x + z > c){nx = x + z - c; ny = y;} else {nx = 0; ny = y;}
		if (c - nx - ny >= 0 && !vis[nx][ny]){
			dis[nx][ny] = dis[x][y] + 1;
			vis[nx][ny] = true;
			q.push(node{nx, ny});
		}
		// y to x
		if (y + x > a){nx = a; ny = y + x - a;} else {nx = y + x; ny = 0;}
		if (c - nx - ny >= 0 && !vis[nx][ny]){
			dis[nx][ny] = dis[x][y] + 1;
			vis[nx][ny] = true;
			q.push(node{nx, ny});
		}
		// y to z
		if (y + z > c){nx = x; ny = y + z - c;} else {nx = x; ny = 0;}
		if (c - nx - ny >= 0 && !vis[nx][ny]){
			dis[nx][ny] = dis[x][y] + 1;
			vis[nx][ny] = true;
			q.push(node{nx, ny});
		}
		// z to x
		if (z + x > a){nx = a; ny = y;} else {nx = z + x; ny = y;}
		if (c - nx - ny >= 0 && !vis[nx][ny]){
			dis[nx][ny] = dis[x][y] + 1;
			vis[nx][ny] = true;
			q.push(node{nx, ny});
		}
		// z to y
		if (z + y > b){nx = x; ny = b;} else {nx = x; ny = z + y;}
		if (c - nx - ny >= 0 && !vis[nx][ny]){
			dis[nx][ny] = dis[x][y] + 1;
			vis[nx][ny] = true;
			q.push(node{nx, ny});
		}
	}
}
int main(){
	cout.tie(0);
	a = read(), b = read(), c = read();
	bfs();
	int ans1 = 1e9, ans2 = 1e9;
	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++){
			int x = 1e9;
			if (!vis[i][j] || c - i - j < 0) continue;
			if (i != 0) x = min(x, i);
			if (j != 0) x = min(x, j);
			if (c - i - j != 0) x = min(x, c - i - j);
			if (x < ans1 || (x == ans1 && dis[i][j] < ans2)){
				ans1 = x;
				ans2 = dis[i][j];
			}
		}
	cout << ans1 << endl << ans2 << endl;
	return 0;
}
