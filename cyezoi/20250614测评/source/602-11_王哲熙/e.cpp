#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>
using namespace std;
using i64 = long long;
const int MAXN = 2e3 + 5;
const int MAXM = 1e4 + 5;
const int MAXK = 205;
int a, b;
struct edge {int v, t, h;};
vector<edge> G[MAXM];
i64 dis[MAXN][MAXK];

int main() {
	int k, n, m;
	cin >> k >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, t, h;
		cin >> u >> v >> t >> h;
		G[u].push_back({v, t, h});
		G[v].push_back({u, t, h});
	}
	cin >> a >> b;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j) dis[i][j] = LLONG_MAX;
	dis[a][0] = 0;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<> > pq;
	pq.emplace(0, a, 0);
	while (!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		int time = get<0>(x), u = get<1>(x), cost = get<2>(x);
		if (u == b) {
			cout << time << "\n";
			return 0;
		}
		if (time > dis[u][cost]) continue;
		for (auto x : G[u]) {
			int v = x.v, t = x.t, h = x.h;
			if (cost + h >= k) continue;
			if (dis[v][cost + h] > time + t) {
				dis[v][cost + h] = time + t;
				pq.emplace(dis[v][cost + h], v, cost + h);
			}
		}
	}
	cout << -1 << "\n";
	return 0;
}
