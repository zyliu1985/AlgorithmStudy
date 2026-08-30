#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int g[3][200005], cnt[3][200005];
bool vis[3][200005];
int ans = 0;

void Dfs(int x, int y) {
	cnt[x][y] = 1;
	vis[x][y] = true;
	if (y+1 > 0 && y+1 <= m && g[x][y+1] == 1 && !vis[x][y+1]) {
		Dfs(x, y+1);
		cnt[x][y] += cnt[x][y+1];
	}
	if (y-1 > 0 && y-1 <= m && g[x][y-1] == 1 && !vis[x][y-1]) {
		Dfs(x, y-1);
		cnt[x][y] += cnt[x][y-1];
	}
	if (y & 1) {
		if (x+1 > 0 && x+1 <= n && g[x+1][y] == 1 && !vis[x+1][y]) {
			Dfs(x+1, y);
			cnt[x][y] += cnt[x+1][y];
		}
		if (x-1 > 0 && x-1 <= n && g[x-1][y] == 1 && !vis[x-1][y]) {
			Dfs(x-1, y);
			cnt[x][y] += cnt[x-1][y];
		}
	}
}

int main() {
	n = 2;
	scanf("%d", &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &g[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] == 1 && !vis[i][j]) {
				Dfs(i, j);
				ans += 3 * cnt[i][j] - 2 * (cnt[i][j]-1);
			}
	printf("%d\n", ans);
	return 0;
}
