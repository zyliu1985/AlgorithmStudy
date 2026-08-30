#include<bits/stdc++.h>
using namespace std;
struct node{
	int t,h;
}use[10010][10010];
int k,n,m,st,ed,ans=INT_MAX;
bool vis[10010];
vector<int>g[10010];
void dfs(int u,int sum,int nk){
	if(nk<=0){
		return;
	}
	if(u==ed){
		ans=min(ans,sum);
		return;
	}
	for(auto v:g[u]){
		if(vis[v]==0){
			vis[v]=1;
			dfs(v,sum+use[u][v].t,nk-use[u][v].h);
			vis[v]=0;
		}
	}
}
int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,t,h;
		scanf("%d%d%d%d",&a,&b,&t,&h);
		g[a].push_back(b);
		g[b].push_back(a);
		use[a][b].t=use[b][a].t=t;
		use[a][b].h=use[b][a].h=h;
	}
	scanf("%d%d",&st,&ed);
	dfs(st,0,k);
	if(ans!=INT_MAX){
		printf("%d",ans);
	}
	else{
		printf("-1");
	}
}
