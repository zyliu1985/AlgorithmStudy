#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int v,t,h,next;
}e[20010];

struct node
{
	int u,k;
	long long w;
};

int cnt,head[2010];
long long d[2010][210];
bool vis[2010][210];

void add(int u,int v,int t,int h)
{
	e[++cnt] = {v,t,h,head[u]};
	head[u] = cnt;
}

bool operator <(node x,node y)
{
	return x.w > y.w;
}

void dijkstra(int s)
{
	memset(d,0x3f,sizeof(d));
	d[s][0] = 0;
	priority_queue<node> q;
	q.push({s,0,d[s][0]});
	while(q.size())
	{
		int u = q.top().u,k = q.top().k;
		q.pop();
		if(vis[u][k])continue;
		vis[u][k] = 1;
		for(int x = head[u];x;x = e[x].next)
		{
			int v = e[x].v,t = e[x].t,h = e[x].h;
			if(k + h > 200)continue;
			if(d[v][k + h] > d[u][k] + t)
			{
				d[v][k + h] = d[u][k] + t;
				q.push({v,k + h,d[v][k + h]});
			}
		}
	}
}

int main()
{
	int k,n,m;
	cin >> k >> n >> m;
	for(int i = 1;i <= m;i++)
	{
		int a,b,t,h;
		cin >> a >> b >> t >> h;
		add(a,b,t,h);
		add(b,a,t,h);
	}
	int s,t;
	cin >> s >> t;
	dijkstra(s);
	long long ans = 1e18;
	for(int i = 0;i < k;i++)
		ans = min(ans,d[t][i]);
	cout << ans;
	return 0;
}
