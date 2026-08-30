#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int k, n, m;
int tot, ver[20005], edge1[20005], edge2[20005], nxt[20005], head[2005];
void Add(int u, int v, int w, int l) {
	ver[++tot] = v;
	edge1[tot] = w;
	edge2[tot] = l;
	nxt[tot] = head[u];
	head[u] = tot;
}

int dis[2005][205];
bool vis[2005][205];

struct Node { int pos, lim; };
struct Node2 { Node pos; int dis; };
bool operator <(Node2 x, Node2 y) { return x.dis > y.dis; }
priority_queue<Node2> q;

void Dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	q.push((Node2){(Node){s, 0}, 0});
	dis[s][0] = 0;
	
	while (!q.empty()) {
		Node u = q.top().pos; q.pop();
		if (vis[u.pos][u.lim]) continue;
		vis[u.pos][u.lim] = true;
		for (int i = head[u.pos]; i; i = nxt[i]) {
			int v = ver[i];
			if (u.lim+edge2[i] >= k) continue;
			if (dis[v][u.lim+edge2[i]] > dis[u.pos][u.lim] + edge1[i]) {
				dis[v][u.lim+edge2[i]] = dis[u.pos][u.lim] + edge1[i];
				q.push((Node2){(Node){v, u.lim+edge2[i]}, dis[v][u.lim+edge2[i]]});
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w, l;
		scanf("%d%d%d%d", &u, &v, &w, &l);
		Add(u, v, w, l);
		Add(v, u, w, l);
	}
	int s, t;
	scanf("%d%d", &s, &t);
	Dijkstra(s);
	int ans = 1e9;
	for (int i = 0; i < k; i++)
		ans = min(ans, dis[t][i]);
	if (ans == 1e9) ans = -1;
	printf("%d\n", ans);

	return 0;
}
