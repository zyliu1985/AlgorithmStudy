#include<bits/stdc++.h>
using namespace std;
int k,n,m,s,t;
struct node
{
	int to,t,h;
};
vector<node> g[10005];
int dist[10005],dish[10005];
bool inq[10005];
queue<int> q;
void spfa(int s)
{
	memset(dist,0,sizeof(dist));
	dist[s]=0;
	dish[s]=k;
	inq[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		inq[x]=false;
		for(int i=1;i<=g[x].size();i++)
		{
			if(dist[x]>dist[i]+g[x][i].t && dish[i]-g[x][i].h<k)
			{
				dist[x]=dist[i]+g[x][i].t;
				dish[x]=dish[i]-g[x][i].h;
				if(!inq[i])
				{
					q.push(i);
					inq[i]=true;
				}
			}
		} 
	}
	return ;
}
int main()
{
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int fro,to,t,h;
		cin>>fro>>to>>t>>h;
		g[fro].push_back({to,t,h});
		g[to].push_back({fro,t,h});
	} 
	cin>>s>>t;
	spfa(s);
	if(dist[t]!=0) cout<<dist[t];
	else cout<<-1;
	return 0;
}
