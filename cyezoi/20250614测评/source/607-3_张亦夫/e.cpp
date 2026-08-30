#include<bits/stdc++.h>
using namespace std;
struct Node{int u,w,h;};
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int n,m,k;
int vis[2005],d[2005],dish[2005],u,v,w,h,s,t;
vector<Node> g[2005];
int solve1(){
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w>>h;
		if(h) continue;
		g[u].push_back({v,w,h});
		g[v].push_back({u,w,h});
	}
	memset(d,0x3f,sizeof(d));
	cin>>s>>t;
	q.push({0,s}); d[s]=0;
	while(!q.empty()){
		int x=q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto u:g[x]){
			if(!vis[u.u]&&d[x]+u.w<d[u.u]){
				d[u.u]=d[x]+u.w;
				q.push({d[u.u],u.u});
			}
		}
	}
	if(d[t]==0x3f3f3f3f) d[t]=-1;
	return d[t];
}
int main(){
	cin>>k>>n>>m;
	if(k==1){
		cout<<solve1();
		return 0;
	}
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w>>h;
		g[u].push_back({v,w,h});
		g[v].push_back({u,w,h});
	}
	memset(d,0x3f,sizeof(d));
	cin>>s>>t;
	q.push({0,s}); d[s]=0;
	while(!q.empty()){
		int x=q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x]=1;
//		cout<<x<<"\n";
		for(auto u:g[x]){
			if(!vis[u.u]&&dish[x]+u.h<k&&d[x]+u.w<d[u.u]){
				d[u.u]=d[x]+u.w;
				dish[u.u]=dish[x]+u.h;
				q.push({d[u.u],u.u});
			}
//			if(dish[x]+u.h<k){
//				d[u.u]=d[x]+u.w;
//				dish[u.u]=dish[x]+u.h;
//				q.push({d[u.u],u.u});
//			}
		}
	}
	if(d[t]==0x3f3f3f3f) d[t]=-1;
	cout<<d[t];
	return 0;
} 
