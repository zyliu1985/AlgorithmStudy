#include<bits/stdc++.h>
struct EDGE{int v,w;};
std::vector<EDGE> g[2005];
int dis[2005];
bool vis[2005];
int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	int k,n,m;std::cin >> k >> n >> m;
	if (k != 1) return std::cout << -1 << '\n',0;
	for (int i = 1;i <= m;i++){
		int a,b,t,h;std::cin >> a >> b >> t >> h;
		if (h == 0){
			g[a].push_back({b,t});
			g[b].push_back({a,t});
		}
	}
	int a,b;std::cin >> a >> b;
	memset(dis,0x3f,sizeof(dis));
	std::queue<int> q;q.push(a);
	vis[a] = 1;dis[a] = 0;
	while (!q.empty()){
		int u = q.front();q.pop();
		for (int i = 0;i < g[u].size();i++){
			int v = g[u][i].v,w = g[u][i].w;
			if (dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				if (!vis[v]) q.push(v),vis[v] = 1;
			}
		}
	}
	std::cout << (dis[b] == dis[0] ? -1 : dis[b]) << '\n';
	return 0;
}
