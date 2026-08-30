#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int u,l;
	bool operator <(const struct node & t)const
	{
		return l>t.l;
	}
}NODE,*PNODE;
int head[2005],nxt[20005],to[20005],weight[20005];
int visited[2005],dist[2005];
priority_queue<NODE> pq;
int tot,a,b;
void add_edge(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[tot]=v;
	weight[tot]=w;
	head[u]=tot;
}
void dijstra(int s)
{
	pq.push((NODE){s,0});
	dist[s]=0;
	while(!pq.empty())
	{
		NODE tmp=pq.top();
		pq.pop();
		if(visited[tmp.u])
			continue;
		dist[tmp.u]=tmp.l;
		visited[tmp.u]=1;
		if(tmp.u==b)
			return;
		for(int i=head[tmp.u];i;i=nxt[i])
		{
			int v=to[i];
			if(visited[v])
				continue;
			pq.push((NODE){v,tmp.l+weight[i]});
		}
		
	}
}
int main()
{
	memset(dist,-1,sizeof(dist));
	memset(visited,0,sizeof(visited));
	int k,n,m,aa,bb,t,h;
	scanf("%d %d %d",&k,&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&aa,&bb,&t,&h);
		if(h!=0)
			continue;
		add_edge(aa,bb,t);
		add_edge(bb,aa,t);
	}
	scanf("%d %d",&a,&b);
	dijstra(a);
	printf("%d\n",dist[b]);
	return 0;
}
