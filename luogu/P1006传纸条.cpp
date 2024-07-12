#include <iostream>
#include <cstring>
using namespace std;

int a[55][55];
int f[55][55][55][55];
int n, m;
int dfs(int x1, int y1, int x2, int y2){
	if (f[x1][y1][x2][y2] != -1) return f[x1][y1][x2][y2];
	if (x1 == n && y1 == m && x2 == n && y2 == m) return 0;
	if (x1 < n && x2 < n)
		f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], dfs(x1+1, y1, x2+1, y2) + a[x1+1][y1] + a[x2+1][y2] * (x1+1 != x2+1 || y1 != y2));
	if (x1 < n && y2 < m)
		f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], dfs(x1+1, y1, x2, y2+1) + a[x1+1][y1] + a[x2][y2+1] * (x1+1 != x2 || y1 != y2+1));
	if (y1 < m && x2 < n)
		f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], dfs(x1, y1+1, x2+1, y2) + a[x1][y1+1] + a[x2+1][y2] * (x1 != x2+1 || y1+1 != y2));
	if (y1 < m && y2 < m)
		f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], dfs(x1, y1+1, x2, y2+1) + a[x1][y1+1] + a[x2][y2+1] * (x1 != x2 || y1+1 != y2+1));
	return f[x1][y1][x2][y2];
}
int main(){
	memset(f, -1, sizeof(f));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	cout << dfs(1, 1, 1, 1) << endl;
	return 0;
}