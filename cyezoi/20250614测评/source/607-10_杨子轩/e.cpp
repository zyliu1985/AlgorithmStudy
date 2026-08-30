#include<bits/stdc++.h>
using namespace std;

const int N=2e3+10;
int k,n,m;
struct node{
	int v,t,h;
};
vector<node> g[N];
int s,e;
int dis[N];
int mo[N];
bool vis[N];
void dfs(){
	queue<int> q;
	q.push(s); vis[s]=1;
	for(int i=1;i<=n;i++) dis[i]=1e9;dis[s]=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(u==e) continue;
		for(auto len:g[u]){
			int v=len.v;
			if(!vis[v]&&len.h==0&&dis[u]+len.t<dis[v]){
				dis[v]=dis[u]+len.t;
				vis[v]=1;
				q.push(v);
			}
		}
	}
	if(dis[e]==1e9) cout<<"-1";
	else cout<<dis[e];
}
	
int main(){
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,t,h;
		cin>>a>>b>>t>>h;
		node len;
		len.v=b;len.t=t;len.h=h;
		g[a].push_back(len);
		len.v=a;
		g[b].push_back(len);
		
	}

	cin>>s>>e;
	dfs();
	
	return 0;
}
