#include <iostream>
using namespace std;
const int MAXN = 1e5 + 5;
int g[MAXN], fa[MAXN], cnt;
int find(int u) {
	while (u != fa[u]) {
		fa[u] = fa[fa[u]];
		u = fa[u];
	}
	return u;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i) cin >> g[i];
	for (int i = 1; i <= n; ++i) {
		int able = find(g[i]);
		if (!able) break;
		fa[able] = able - 1;
		++cnt;
	}
	cout << cnt << "\n";
	return 0;
}
