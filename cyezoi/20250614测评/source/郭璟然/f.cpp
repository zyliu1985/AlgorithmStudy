#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, a[3005], b[105], c[3105], sz, ans;
int f[3105][2];
bool vis[105];

int Calc() {
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n + m; i++) {
		f[i][0] = max(f[i-1][0], f[i-1][1]);
		f[i][1] = f[i-1][0] + c[i];
	}
	return max(f[n+m][0], f[n+m][1]);
}

void Dfs(int step, int _1) {
	if (step > n + m) {
		ans = max(ans, Calc());
		return ;
	}
	if (_1 <= n) {
		c[step] = a[_1];
		Dfs(step + 1, _1 + 1);
	}
	for (int i = 1; i <= m; i++) {
		if (!vis[i]) {
			vis[i] = true;
			c[step] = b[i];
			Dfs(step + 1, _1);
			vis[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	Dfs(1, 1);
	printf("%d", ans);
	return 0;
}
