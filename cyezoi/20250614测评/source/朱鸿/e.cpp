#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 5;
const int inf = 1e9;

int k, n, m;

namespace t1 {
	int dis[maxn];
	bool vis[maxn];
	struct Edge {
		int to, t;
		friend bool operator<(Edge x, Edge y) {
			return x.t < y.t;
		}
		friend bool operator>(Edge x, Edge y) {
			return x.t > y.t;
		}
	};
	vector<Edge> g[maxn];
	
	inline void dijkstra(int st) {
		for (int i = 1; i <= n; i++) {
			dis[i] = inf;
		}
		dis[st] = 0;
		priority_queue<Edge, vector<Edge>, greater<Edge> > q;
		q.push({st, 0});
		while (!q.empty()) {
			int u = q.top().to;
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (const auto& i : g[u]) {
				int v = i.to, w = i.t;
				if (dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					q.push({v, dis[v]});
				}
			}
		}
	}
	
	inline int solve() {
		for (int i = 1; i <= m; i++) {
			int u, v, t, h;
			cin >> u >> v >> t >> h;
			if (h >= 1) continue;
			g[u].push_back({v, t});
			g[v].push_back({u, t});
		}
		int a, b;
		cin >> a >> b;
		dijkstra(a);
		return (dis[b] == inf) ? -1 : dis[b];
	}
}

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> n >> m;
	cout << t1::solve() << "\n";
	return 0;
}
