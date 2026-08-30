#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
using ull= unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f, N = 3e5, M = 2e4, MK = 200;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
int K, n, m, hd[N + 5], to[M + 5], ut[M + 5], ms[M + 5], nx[M + 5], ce, dis[N + 5][MK + 5], ans = INF;
bitset<MK + 5> vis[N + 5];
struct Nd{
	int n, k, d;
	Nd(int n, int k, int d) : n(n), k(k), d(d) {}
	bool operator< (Nd o) const{ return d > o.d; }
};
priority_queue<Nd> q;

void ae(int u, int v, int t, int h){
	nx[++ ce] = hd[u];
	to[ce] = v;
	ut[ce] = t;
	ms[ce] = h;
	hd[u] = ce;
}

void dijkstra(int s){
	memset(dis, 0x3f, sizeof(dis));
	q.push(Nd(s, 0, (dis[s][0] = 0)));
	while(!q.empty()){
		Nd k = q.top();
		q.pop();
		if(vis[k.n][k.k]) continue;
		else vis[k.n].set(k.k);
		for(int x = hd[k.n]; x; x = nx[x]) if(k.k + ms[x] < K && !vis[to[x]][k.k + ms[x]] && dis[to[x]][k.k + ms[x]] > k.d + ut[x]) q.push(Nd(to[x], k.k + ms[x], (dis[to[x]][k.k + ms[x]] = k.d + ut[x])));
	}
}

int main(){
	int u, v, t, h;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> K >> n >> m;
	while(m --){
		cin >> u >> v >> t >> h;
		ae(u, v, t, h);
		ae(v, u, t, h);
	}
	cin >> u >> v;
	dijkstra(u);
	for(int i = 0; i < K; ++ i) ans = min(ans, dis[v][i]);
	cout << (ans == INF ? -1 : ans);
}

