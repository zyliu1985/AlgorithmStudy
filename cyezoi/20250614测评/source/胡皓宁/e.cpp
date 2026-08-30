#include <bits/stdc++.h>
using namespace std;
struct line {
	int v, t, h;
	line(int V, int T, int H) {
		v = V, t = T, h = H;
	}
};
vector<line> edges[2020];
int k, n, m, a, b, mint = 1e9;
bool route[2020];
inline void dfs(int x, int t, int h) {
	if (x == b) {
		mint = min(mint, t);
		return;
	}
	route[x] = 1;
	int len = edges[x].size();
	for (int Y = 0; Y < len; Y ++) {
		line y = edges[x][Y];
		if (! route[y.v] && h > y.h)
			dfs(y.v, h - y.h, t + y.t);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int t, h;
		cin >> a >> b >> t >> h;
		edges[a].push_back(line(b, t, h)), edges[b].push_back(line(a, t, h));
	}
	cin >> a >> b;
	dfs(a, 0, k);
	if (mint != 1e9)
		cout << mint;
	else
		cout << -1;
}
