#include <bits/stdc++.h>
using namespace std;
struct node{int v,w,h;};
int k,n,m,s,t,dis[2010],dik[2010];
vector<node> G[2010];
bool vis[2010];
void spfa(int s){
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	dik[s] = 0;
	vis[s] = 1;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = 0;i < G[u].size();i++){
			int v = G[u][i].v,w = G[u][i].w,h = G[u][i].h;
			if (dis[v] > dis[u] + w && dik[u] + h < k){
				dis[v] = dis[u] + w;
				dik[v] += h;
				if (!vis[v]) vis[v] = 1,q.push(v);
			}
		}
	}
}
int main(){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	cin >> k >> n >> m;
	for (int i = 1;i <= m;i++){
		int u,v,w,h;
		cin >> u >> v >> w >> h;
		G[u].push_back((node){v,w,h});
		G[v].push_back((node){u,w,h});
	}
	cin >> s >> t;
	spfa(s);
	cout << (dis[t] == 0x3f3f3f3f ? -1 : dis[t]);
}
