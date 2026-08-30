#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 2;
const int M = 202;
struct edge{int v,w,gap;};
struct node
{
	int u,I,d;
	bool operator < (node oth) const
	{
		return d > oth.d;
	}
};
int m,n,dis[N][M];
vector <edge> vec[N];
void bfs(int s)
{
	memset(dis,0x3f,sizeof(dis));
	priority_queue <node> q;
	dis[s][0] = 0;
	q.push({s,0,0});
	while(!q.empty())
	{
		int u = q.top().u,I = q.top().I,d = q.top().d; q.pop();
		if(d != dis[u][I]) continue;
		for(int i = 0; i < vec[u].size(); i++)
		{
			edge e = vec[u][i];
			if(I + e.gap >= m) continue;
			if(d + e.w < dis[e.v][I + e.gap])
			{
				dis[e.v][I + e.gap] = d + e.w;
				q.push({e.v,I + e.gap,dis[e.v][I + e.gap]});
			}
		}
	}
}
signed main()
{
	int T;
	scanf("%d%d%d",&m,&n,&T);
	while(T--)
	{
		int u,v,w,gap;
		scanf("%d%d%d%d",&u,&v,&w,&gap);
		vec[u].push_back({v,w,gap});
		vec[v].push_back({u,w,gap});
	}
	int s,t; scanf("%d%d",&s,&t);
	bfs(s); int ans = 2e9;
	for(int i = 0; i < m; i++)
		ans = min(ans,dis[t][i]);
	if(ans == 2e9) printf("-1");
	else printf("%d",ans);
}






