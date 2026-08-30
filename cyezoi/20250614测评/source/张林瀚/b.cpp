#include <iostream>

using namespace std;
const int C = 2e5 + 10;

int c, ans;
int G[2][C];
bool vis[2][C];
bool fa[2][C], fb[2][C]; //分别表示这个点的左重边和上|下重边是否被算过 

int dfs(int x, int y) {
	if (vis[x][y] || G[x][y] == 0 || y > c) return 0;
	vis[x][y] = 1;
	int lx = x, ly = y - 1; //左边的点 
	int ux = (x + 1) % 2, uy = y; //上|下的点 
	int S = 3;
	if (ly >= 1 && G[lx][ly] == 1) {
		if (!fa[lx][ly]) S -= 2, fa[lx][ly] = fa[x][y] = 1;
	} if (G[ux][uy] == 1) {
		if (!fb[ux][uy]) S -= 2, fb[ux][uy] = fb[x][y] = 1;
	}
	int S2 = dfs(x, y + 1), S3 = dfs((x + 1) % 2, y);
	return S + S2 + S3;
}

int main() {
	cin >> c;
	for (int i = 1; i <= c; i++) cin >> G[0][i];
	for (int i = 1; i <= c; i++) cin >> G[1][i];
	for (int i = 2; i <= c; i += 2) fb[0][i] = fb[1][i] = 1;
	for (int i = 1; i <= c; i++) {
		if (!vis[0][i] && G[0][i] == 1) ans += dfs(0, i);
		if (!vis[1][i] && G[1][i] == 1) ans += dfs(1, i);
	}
	cout << ans << "\n";
	return 0;
}
