#include <iostream>
#include <cstring>
using namespace std;

int a[15][15];
int f[15][15][15][15];
int n;
int dfs(int x1, int y1, int x2, int y2){
	if (f[x1][y1][x2][y2] != -1) return f[x1][y1][x2][y2];
	if (x1 == n && y1 == n && x2 == n && y2 == n) return 0;
	if (x1 < n && x2 < n)
		f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], dfs(x1+1, y1, x2+1, y2) + a[x1+1][y1] + a[x2+1][y2] * (x1+1 != x2+1 || y1 != y2));
	if (x1 < n && y2 < n)
		f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], dfs(x1+1, y1, x2, y2+1) + a[x1+1][y1] + a[x2][y2+1] * (x1+1 != x2 || y1 != y2+1));
	if (y1 < n && x2 < n)
		f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], dfs(x1, y1+1, x2+1, y2) + a[x1][y1+1] + a[x2+1][y2] * (x1 != x2+1 || y1+1 != y2));
	if (y1 < n && y2 < n)
		f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], dfs(x1, y1+1, x2, y2+1) + a[x1][y1+1] + a[x2][y2+1] * (x1 != x2 || y1+1 != y2+1));
	return f[x1][y1][x2][y2];
}
int main(){
	memset(f, -1, sizeof(f));
	cin >> n;
	int x, y, v;
	cin >> x >> y >> v;
	while (x != 0 && y != 0 && v != 0){
		a[x][y] = v;
		cin >> x >> y >> v;
	}
	cout << dfs(1, 1, 1, 1) + a[1][1] << endl;
	return 0;
}