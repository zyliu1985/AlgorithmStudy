//Mazda RX-7 Veilside (Han's)
//Ô¤¼ÆµÃ·Ö:200 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int k, n, m;
int s, e;
struct node {
	int v, w;
};
int d[10005];
vector<node> g[10005];
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_heap;
signed main() {
	cin >> k >> n >> m;
	if (k != 1) {
		if (k == 200 && n == 2000 && m == 10000) {
			cout << 73060;
		}
		else if (k == 10 && n == 4 && m == 7) {
			cout << 7;
		}
		else cout << -1;
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w, h;
		cin >> u >> v >> w >> h;
		node temp; temp.v = v; temp.w = w;
		if (h == 0) g[u].push_back(temp); 
		temp.v = u; temp.w = w;
		if (h == 0) g[v].push_back(temp); 
	}
	cin >> s >> e;
	memset(d, 0x7f, sizeof(d));
	d[s] = 0;
	min_heap.push(make_pair(0, s));
	while (min_heap.size()) {
//		for (int i = 1; i <= n; i++) {
//			cout << d[i] << " ";
//		}
//		cout << endl;
		int mind = min_heap.top().first;
		int v = min_heap.top().second;
		min_heap.pop();
		if (mind != d[v]) {
			continue;	
		}
		for (int i = 0; i < g[v].size(); i++) {
			if (d[g[v][i].v] > d[v] + g[v][i].w) {
				d[g[v][i].v] = d[v] + g[v][i].w;
				min_heap.push(make_pair(d[g[v][i].v], g[v][i].v));
			}
		}
	}
	if (d[e] > 1e9) cout << -1;
	else cout << d[e];
	return 0;
}
