#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#define int long long
using namespace std;

const int mod = 998244353;
int n, m, k;
int h[305][305];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[305][305];
struct node{
	int x, y, c, ch;
};
queue<node> q;
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
long long mi(int di, int up){
	long long re = 1;
	for (int i = 1; i <= up; i++)
		re = (re * di) % mod;
	return re;
}
void bfs(int x, int y, int c, int d){
	q.push({x, y, c, 1});
	vis[x][y] = true;
	while (!q.empty()){
		int xx = q.front().x;
		int yy = q.front().y;
		int cc = q.front().c;
		int ch = q.front().ch;
		q.pop();
		h[xx][yy] += cc * ch;
		if (cc > d)
			for (int i = 0; i < 4; i++){
				int nx = xx + dx[i];
				int ny = yy + dy[i];
				if (vis[nx][ny] || !in(nx, ny)) continue;
				vis[nx][ny] = true;
				q.push({nx, ny, cc - d, -ch});
			}
	}
}
signed main(){
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++){
		int x, y, c, d;
		cin >> x >> y >> c >> d;
		bfs(x, y, c, d);
		memset(vis, 0, sizeof(vis));
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++)
//			cout << h[i][j] << ' ';
//		cout << endl;
//	}
	for (int i = 1; i <= n; i++){
		long long sum = 0;
		for (int j = 1; j <= m; j++){
			sum = (sum + (h[i][j] * mi(233, j)) % mod) % mod;
			while(sum < 0) sum += mod;
		}
		cout << sum  << ' ';
	}
	return 0;
}