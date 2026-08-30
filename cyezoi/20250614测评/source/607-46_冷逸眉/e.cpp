#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct nod{
	int x,w,k;
	bool operator <(const nod &a) const{
		return w > a.w;
	}
};
int dis[2005][205],n,m,K,A,B,minn = 0x7f7f7f7f;
bool vis[2005][205];
vector <nod> V[2005];
void dijkstra(int x){
	memset(dis,0x7f,sizeof dis);
	priority_queue <nod> pq;
	pq.push({x,0,K});
	dis[x][K] = 0;
	while(!pq.empty()){
		nod tx = pq.top();
		pq.pop();
		if(vis[tx.x][tx.k]) continue;
		vis[tx.x][tx.k] = 1;
		for(int i = 0;i < V[tx.x].size();i++){
			for(int j = V[tx.x][i].k;j <= K;j++){
				int xx = V[tx.x][i].x;
				if(dis[xx][j - V[tx.x][i].k] > dis[tx.x][j] + V[tx.x][i].w){
					dis[xx][j - V[tx.x][i].k] = dis[tx.x][j] + V[tx.x][i].w;
					pq.push(nod{xx,dis[xx][j - V[tx.x][i].k],j - V[tx.x][i].k});
				}
			}
		}
	}
}
int main(){
	cin >> K >> n >> m;
	for(int i = 1;i <= m;i++){
		int a,b,t,h;
		cin >> a >> b >> t >> h;
		V[a].push_back({b,t,h});
		V[b].push_back({a,t,h});
	}
	cin >> A >> B;
	dijkstra(A);
	for(int i = 1;i <= K;i++){
		minn = min(minn,dis[B][i]);
	}
	if(minn < 1e9) cout << minn;
	else cout << -1;
	return 0;
}
