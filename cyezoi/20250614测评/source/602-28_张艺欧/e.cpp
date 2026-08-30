#include<bits/stdc++.h>
using namespace std;
int n, m, k, st, ed, dis[2010];
bool vis[2010];
struct g{
	int to, w, val;
	bool operator<(const g& x)const{
		return w>x.w;
	}
};
struct line{
	int to, w, val;
};
vector<line> l[10010];
priority_queue<g> q;
void dijk(){
	memset(dis, 0x7f, sizeof dis);
	dis[st] = 0;
	q.push(g{st, 0, 0});
	while(!q.empty()){
		int u = q.top().to, now = q.top().val;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(int i=0; i<l[u].size(); ++i){
			int v = l[u][i].to, w = l[u][i].w, val = l[u][i].val;
			if(dis[u]+w<dis[v] && now+val<k){
				dis[v] = dis[u]+w;
				q.push(g{v, dis[v], now+val});
			}
		}
	}
}
int main(){
//	freopen("data_2.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> k >> n >> m;
	for(int i=1; i<=m; ++i){
		int u, v, t, h;
		cin >> u >> v >> t >> h;
		l[u].push_back(line{v, t, h});
		l[v].push_back(line{u, t, h});
	}
	cin >> st >> ed;
	dijk();
	if(!vis[ed]){
		cout << "-1" << endl;
		return 0;
	}
	cout << dis[ed] << endl;
	return 0;
}

