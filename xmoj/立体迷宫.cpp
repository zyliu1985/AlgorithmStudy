#include <iostream>
#include <algorithm>
using namespace std;

int mp[55][55];
bool vis[55][55];
int h, w;
void dfs(int x, int y){
	vis[x][y] = true;
	// 平路/一格梯子 
	if (x > 1 && abs(mp[x-1][y] - mp[x][y]) <= 1 && !vis[x-1][y]) dfs(x-1, y);  
	if (x < h && abs(mp[x+1][y] - mp[x][y]) <= 1 && !vis[x+1][y]) dfs(x+1, y);  
	if (y > 1 && abs(mp[x][y-1] - mp[x][y]) <= 1 && !vis[x][y-1]) dfs(x, y-1);  
	if (y < w && abs(mp[x][y+1] - mp[x][y]) <= 1 && !vis[x][y+1]) dfs(x, y+1);  
	// 两个
	if (x > 2 && mp[x-1][y] < mp[x][y] && mp[x-2][y] == mp[x][y] && !vis[x-2][y]) dfs(x-2, y);  
	if (x < h-1 && mp[x+1][y] < mp[x][y] && mp[x+2][y] == mp[x][y] && !vis[x+2][y]) dfs(x+2, y);  
	if (y > 2 && mp[x][y-1] < mp[x][y] && mp[x][y-2] == mp[x][y] && !vis[x][y-2]) dfs(x, y-2);  
	if (y < w-1 && mp[x][y+1] < mp[x][y] && mp[x][y+2] == mp[x][y] && !vis[x][y+2]) dfs(x, y+2);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout); 
	cin >> h >> w;
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++){
			char c;
			cin >> c;
			mp[i][j] = c - '0';
		}
	dfs(sx, sy);
	if (vis[tx][ty]) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}



