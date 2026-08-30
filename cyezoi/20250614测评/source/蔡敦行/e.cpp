#include<queue>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e3+5;
int k,n,m,a,b;
int ans=1e9;
struct edge
{
	int v,t,h;
	edge(int x,int y,int z)
	{
		v=x;t=y;h=z;
	}
};
vector<edge>g[N];
void dfs(int u,int t,int h)
{
	if(h>=k)return;
	if(t>=ans)return;
	if(u==b)
	{
		ans=min(ans,t);
		return;
	}
	for(int i=0;i<(int)g[u].size();i++)
		dfs(g[u][i].v,t+g[u][i].t,h+g[u][i].h);
}
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,t,h;
		scanf("%d%d%d%d",&u,&v,&t,&h);
		g[u].push_back(edge(v,t,h));
		g[v].push_back(edge(u,t,h));
	}
	scanf("%d%d",&a,&b);
	dfs(a,0,0);
	printf("%d\n",ans);
	return 0;
}
