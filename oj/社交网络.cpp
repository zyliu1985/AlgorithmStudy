#include <iostream>
#include <cstring>
#include <queue>
#define int long long
using namespace std;

bool b[55][55], vis[55], flag[55];
int dis[55];
queue<int> q;
void sta(){
	b[2][6] = true;b[6][2] = true;
	b[1][6] = true;b[6][1] = true;
	b[3][6] = true;b[6][3] = true;
	b[4][6] = true;b[6][4] = true;
	b[5][6] = true;b[6][5] = true;
	b[7][6] = true;b[6][7] = true;
	b[3][4] = true;b[4][3] = true;
	b[3][5] = true;b[5][3] = true;
	b[4][5] = true;b[5][4] = true;
	b[7][8] = true;b[8][7] = true;
	b[8][9] = true;b[9][8] = true;
	b[9][10] = true;b[10][9] = true;
	b[3][15] = true;b[15][3] = true;
	b[12][9] = true;b[9][12] = true;
	b[10][11] = true;b[11][10] = true;
	b[11][12] = true;b[12][11] = true;
	b[13][15] = true;b[15][13] = true;
	b[12][13] = true;b[13][12] = true;
	b[13][14] = true;b[14][13] = true;
	b[18][16] = true;b[16][18] = true;
	b[18][17] = true;b[17][18] = true;
	b[16][17] = true;b[17][16] = true;
}
void i(int x, int y){
	b[x][y] = true;
	b[y][x] = true;
}
void d(int x, int y){
	b[x][y] = false;
	b[y][x] = false;
}
int n(int x){
	int re = 0;
	for (int i = 1; i <= 50; i++)
		if (b[x][i]) re++;
	return re;
}
int f(int x){
	int re = 0;
	memset(flag, false, sizeof(flag));
	flag[x] = true;
	for (int i = 1; i <= 50; i++)
		if (b[x][i]) flag[i] = true;
	for (int i = 1; i <= 50; i++){
		if (b[x][i])
			for (int j = 1; j <= 50; j++)
				if (b[i][j] && !flag[j]){
					re++;
					flag[j] = true;
				}
	}
	return re;
}
int s(int x, int y){
	memset(vis, false, sizeof(vis));
	while (!q.empty()) q.pop();
	q.push(x);
	dis[x] = 0;
	vis[x] = true;
	while (!q.empty()){
		int a = q.front();
		q.pop();
		if (a == y) return dis[a];
		for (int i = 1; i <= 50; i++)
			if (b[a][i] && !vis[i]){
				q.push(i);
				dis[i] = dis[a] + 1;
				vis[i] = true;
			}
	}
	return -1;
}
signed main(){
	sta();
	char key = ' ';
	while (key != 'q'){
		cin >> key;
		if (key == 'i'){
			int x, y;
			cin >> x >> y;
			i(x, y);
		} else if (key == 'd'){
			int x, y;
			cin >> x >> y;
			d(x, y);
		} else if (key == 'n'){
			int x;
			cin >> x;
			cout << n(x) << endl;
		} else if (key == 'f'){
			int x;
			cin >> x;
			cout << f(x) << endl;
		} else if (key == 's'){
			int x, y;
			cin >> x >> y;
			int ans = s(x, y);
			if (ans == -1) cout << "Not connected" << endl;
			else cout << ans << endl;
		}
	}
}