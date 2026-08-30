#include<bits/stdc++.h>

using namespace std;

#define int long long

struct node {
	int v, t, k;
};

struct Dis {
	int u, t, k;
	friend bool operator < (const Dis& a, const Dis& b) {
		return a.t > b.t;
	}
};

priority_queue<Dis> pq;
vector<node> g[10004];
int k, n, m, A, B;
int dis[2003];

void dij() {
	memset(dis, 0x3f, sizeof dis);
	pq.push(Dis{A, 0, 0});
	while (!pq.empty()) {
		Dis h = pq.top(); pq.pop();
		int u = h.u, t = h.t, K = h.k;
		if (K >= k) continue;
		if (dis[u] != 0x3f3f3f3f3f3f3f3f) continue;
		dis[u] = t;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v, shi = g[u][i].t, mosun = g[u][i].k;
			pq.push(Dis{v, shi + t, mosun + K});
		}
	}
	if (dis[B] == 0x3f3f3f3f3f3f3f3f) cout << -1;
	else cout << dis[B];
}

signed main() {
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, t, h;
		cin >> u >> v >> t >> h;
		g[u].push_back(node{v, t, h});
		g[v].push_back(node{u, t, h});
	}
	cin >> A >> B;
	dij();
	return 0;
}
