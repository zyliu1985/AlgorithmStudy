#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool vis[10][200010], a[10][200010];
void dfs(int x, int y){
	if (x < 1 || x > 2) return ;
	if (vis[x][y]) return ;
	if (!a[x][y]) return ;
	vis[x][y] = 1;
//	printf("%d %d\n", x, y);
	ans -= 2;
	if (y % 2 != 0)
		dfs(x + 1, y);
	dfs(x, y + 1);
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[1][i];
	for (int i = 1; i <= n; i++) cin >> a[2][i];
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j])
				ans += 3;
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= n; j++)
			if (!vis[i][j] && a[i][j])
				ans += 2, dfs(i, j);
	cout << ans << endl;
	return 0;
}
