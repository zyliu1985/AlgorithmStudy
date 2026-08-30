#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long Inf=1e17+9;
const long long Mod=1e9+7;

int n,k,m;

struct edge
{
	int x,y,nxt;
	ll w;
} E[400009];

struct gt
{
	int a,b;
	ll t;
};
vector<gt> vec;

int head[100009],pre[1000009],tot=0;
struct node
{
	int x;
	ll d;
	bool operator<(const node A)const
	{
		return d>A.d;
	}
};
priority_queue<node> Q;
ll dis[100009];
bool vis[100009];

inline void addedge(int x,int y,ll w)
{
	E[++tot]=(edge){x,y,head[x],w};
	head[x]=tot;
	return;
}

inline ll dijkstra(int s,int t)
{
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	pre[s]=0;
	Q.push((node){s,0});
	while(!Q.empty())
	{
		int now=Q.top().x;
		Q.pop();
		if(vis[now])
			continue;
		vis[now]=true;
		for(int i=head[now];~i;i=E[i].nxt)
		{
			int to=E[i].y;
			if(!vis[to]&&dis[to]>dis[now]+E[i].w)
			{
				dis[to]=dis[now]+E[i].w;
				pre[to]=now;
				Q.push((node){to,dis[to]});
			}
		}
	}
	return dis[t];
}


void solve()
{
	scanf("%d %d %d",&k,&n,&m);
	memset(head,-1,sizeof(head));
	memset(pre,0x3f,sizeof(pre));
	for(int i=1;i<=m;i++)
	{
		int a,b,h;
		ll t;
		scanf("%d %d %lld %d",&a,&b,&t,&h);
		if(h==0)
		{
			addedge(a,b,t);
			addedge(b,a,t);
		}
		else if(h>1)
			continue;
		else vec.push_back((gt){a,b,t});
	}
	int s,t;
	scanf("%d %d",&s,&t);
	ll ans=dijkstra(s,t);
	printf("%lld\n",ans);
	for(int i=0;i<vec.size();i++)
	{
		if(i>=1) tot--;
		E[++tot]=(edge){vec[i].a,vec[i].b,head[vec[i].a],vec[i].t};
		head[vec[i].a]=tot;
		ans=(ll)min(ans,dijkstra(s,t));
	}
	printf("%lld\n",ans);
}

signed main()
{
	ll T=1,i=1;
	while(T--)
		solve();
	return 0;
}
