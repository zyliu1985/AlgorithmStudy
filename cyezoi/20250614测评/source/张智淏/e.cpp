#include<bits/stdc++.h>
using namespace std;
int k,n,m,u,v,w,h,s,t,dis[2005];
bool vis[2005];
vector<int> a[2005],b[2005];
struct node{
	int dis,p;
	bool operator >(const node &x)const
	{
		return x.dis<dis;
	}
};
priority_queue<node,vector<node>,greater<node> > q;
int main(){
	scanf("%d%d%d",&k,&n,&m);
	if(k!=1){
		printf("-1");
		return 0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&u,&v,&w,&h);
		if(h==0){
			a[u].push_back(v);
			b[u].push_back(w);
			a[v].push_back(u);
			b[v].push_back(w);
		}
	}
	scanf("%d%d",&s,&t);
	for(int i=1;i<=n;i++){
		dis[i]=2e9;
	}
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		u=q.top().p;
		w=q.top().dis;
		if(vis[u]){
			q.pop();
			continue;
		}
		vis[u]=1;
		q.pop();
		for(int i=0;i<a[u].size();i++){
			if(!vis[a[u][i]]&&dis[a[u][i]]>b[u][i]+w){
				dis[a[u][i]]=b[u][i]+w;
				q.push({dis[a[u][i]],a[u][i]});
			}
		}
	}
	if(dis[t]==2e9)printf("-1");
	else printf("%d",dis[t]);
	return 0;
}
