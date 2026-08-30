#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e3+10;
struct node
{
	ll y,l;
};
vector<node> v[N];
ll vis[N],dis[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k,n,m;
	cin>>k>>n>>m;
	if(k!=1)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		ll x,y,t,h;
		cin>>x>>y>>t>>h;
		if(h) continue; 
		v[x].push_back({y,t});
		v[y].push_back({x,t});
	}
	int s,t;
	cin>>s>>t;
	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(node t:v[x])
		{
			int y=t.y;
			if(dis[x]+t.l<dis[y])
			{
				dis[y]=dis[x]+t.l;
				if(vis[y]==0)
				{
					vis[y]=1;
					q.push(y); 
				}
			}
		}
	}
	cout<<dis[t];
	return 0;
}

