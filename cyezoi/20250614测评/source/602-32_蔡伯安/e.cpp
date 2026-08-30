#include<bits/stdc++.h>
using namespace std;
int k,n,m,x,y,minn=0x3f3f3f3f;
bool vis[2010];
struct node
{
	int v,t,w;
};
vector<node> edges[2010];
void dfs(int idx,int ans)
{
	if(idx==y)
	{
		minn=min(minn,ans);
		return;
	}
	if(ans>=minn) return;
	for(auto s:edges[idx])
	{
		if(!vis[s.v]&&s.w==0)
		{
			vis[s.v]=1;
			dfs(s.v,s.t+ans);
			vis[s.v]=0;
		}
	}
}
int main()
{
	cin>>k>>n>>m;
	for(int i=1,u,v,t,w;i<=m;i++)
	{
		cin>>u>>v>>t>>w;
		edges[u].push_back({v,t,w});
		edges[v].push_back({u,t,w});
	}
	cin>>x>>y;
	if(k==1) 
	{
		dfs(x,0);
		if(minn==0x3f3f3f3f) cout<<-1;
		else cout<<minn;
	}
	else cout<<-1;
}
