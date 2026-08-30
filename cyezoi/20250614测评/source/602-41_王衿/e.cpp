#include<bits/stdc++.h>

using namespace std;

int k, n, m, a, b, t, h, ans = INT_MAX, dis[205][2005];

struct node {
	int v, t, h;
	bool operator > (const node &x) const {
		return t < x.h;
	}
};

vector<node> g[2005];

inline int read() {
	int res = 0, tmp = getchar();
	while (tmp < '0' || '9' < tmp) tmp = getchar();
	while ('0' <= tmp && tmp <= '9') res = res * 10 + tmp - '0', tmp = getchar();
	return res;
}


int main() {
	memset(dis, 127, sizeof dis);
	priority_queue<node, vector<node>, greater<node> > q;
	k = read(), n = read(), m = read();
	for (int i=0; i<m; ++i) {
		a = read(), b = read(), t = read(), h = read();
		g[a].push_back((node){b, t, h});
		g[b].push_back((node){a, t, h});
	}
	a = read(), b = read();
	for (int i=0; i<k; ++i) {
		dis[i][a] = 0;
	}
	q.push((node){a, 0, 0});
	while (!q.empty()) {
		node top = q.top();
		q.pop();
		for (int i=0; i<g[top.v].size(); ++i) {
			const node &tmp = g[top.v][i];
			if (top.h + tmp.h < k && dis[top.h + tmp.h][tmp.v] > top.t + g[top.v][i].t) {
				dis[top.h + tmp.h][tmp.v] = top.t + g[top.v][i].t;
				if (tmp.v != b) q.push((node){tmp.v, dis[top.h + tmp.h][tmp.v], top.h + tmp.h});
				else ans = min(ans, dis[top.h + tmp.h][tmp.v]);
			}
		}
	}
	if (ans == INT_MAX) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}

/*
10 4 7
1 2 4 4
1 3 7 2
3 1 8 1
3 2 2 2
4 2 1 6
3 4 1 1
1 4 6 12
1 4

*/

