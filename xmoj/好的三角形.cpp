#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int a[15][15];
int dx[6] = {0, 1, 0, -1, 1, -1};
int dy[6] = {1, 0, -1, 0, 1, -1};
bool b[15][15];
int dis[15][15];
int n, k, p;
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= x;
}
struct node{
	int x, y;
};
queue<node> q;
int bfs(int x, int y){
	while (!q.empty()) q.pop();
	q.push({x, y});
	dis[x][y] = 0;
	while (!q.empty()){
		int nx = q.front().x, ny = q.front().y;
		q.pop();
		if (b[nx][ny]) return dis[nx][ny];
		for (int i = 0; i < 6; i++){
			int zx = nx + dx[i], zy = ny + dy[i];
			if (in(zx, zy) && !dis[zx][zy] && (zx != x || zy != y)){
				q.push({zx, zy});
				dis[zx][zy] = dis[nx][ny] + 1;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout); 
	cin >> n >> k >> p;
	for (int i = 1; i <= k; i++){
		int x, y;
		cin >> x >> y;
		b[x][y] = true;
	}
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			memset(dis, 0, sizeof(dis)), a[i][j] = bfs(i, j);
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= i; j++)
//			cout << a[i][j] << ' ';
//		cout << '\n';
//	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++){
			int SUM = 0;
			for (int kk = i; kk <= n; kk++){
				int sum = 0;
				for (int l = j; l <= j+kk-i; l++)
					sum += a[kk][l];
				SUM += sum;
				if (SUM >= p) ans++;
			}
		}
	cout << ans <<'\n';
	return 0;
}



