#include <iostream>
using namespace std;

int read(){
	int re = 0, type = 1;
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
int n, m;
char c[205][205];
bool vis[205][205];
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
void dfs(int x, int y){
	if (vis[x][y] || c[x][y] == '#' || !in(x, y)) return;
	vis[x][y] = true;
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);
}
int main(){
	cin.tie(0);
	cout.tie(0);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!vis[i][j] && c[i][j] == '.'){
				dfs(i, j);
				ans++; 
			}
	cout << ans << endl;
	return 0;
}
