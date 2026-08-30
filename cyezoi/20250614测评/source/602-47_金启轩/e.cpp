#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a, b, t, h;
int be, en;
int mindis[2003], fa[2003], hh[2003][2003];
bool vis[2003];
struct STR{int v, w, h;};
vector <STR> g[2003];
struct DIS{
	int id, dis;
	friend bool operator < (DIS a, DIS b) {
		return a.dis > b.dis;
	}
};
priority_queue <DIS> pq;
void init() {
	while (!pq.empty()) pq.pop();
	memset(vis, 0, sizeof(vis));
	memset(mindis, 0x7f7f7f7f, sizeof(mindis));
	fa[1] = 0;
}
void djstl(int maxh) {
	init();
	pq.push((DIS){be, 0});
	while (!pq.empty()) {
		DIS h = pq.top();
		pq.pop();
		int u = h.id, disu = h.dis;
		if (!vis[u]) vis[u] = 1, mindis[u] = disu;
		else continue;
		for (int i = 0; i < g[u].size(); ++i) {
			if (g[u][i].h > maxh) continue;
			int v = g[u][i].v, w = g[u][i].w;
			if (mindis[u] + w < mindis[v]) {
				mindis[v] = mindis[u] + w, fa[v] = u;
				pq.push((DIS){v, mindis[v]});
			}
		}
	}
}
int sans;
int dfs(int u, int v) {
	if (fa[u] == 0) return hh[u][v];
	return dfs(fa[u], u) + hh[u][v];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b >> t >> h;
		g[a].push_back((STR){b, t, h});
		g[b].push_back((STR){a, t, h});
		hh[a][b] = hh[b][a] = h;
	}
	cin >> be >> en;
	if (k == 1) {
		djstl(0);
		cout << mindis[en] << endl;
		return 0;
	}
	int l = 0, r = k, mid, ans = 0x7f7f7f7f;
	while (l <= r) {
		mid = (l + r) / 2;
		djstl(mid);
		if (dfs(en, 0) < k) ans = min(ans, mindis[en]), r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}

