#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct node
{
	int x,t,h;
};
struct route
{
	int x;
	long long t;
	int h;
};
bool operator<(route x,route y)
{
	if(x.t!=y.t)
	{
		return x.t>y.t;
	}
	return x.h>y.h; 
}
vector<node>v[2005];
bool vis[2005];
int st,en,n,m,k;
long long f()
{
	priority_queue<route>q;
	q.push({st,0,0});
	while(!q.empty())
	{
		int x=q.top().x,h=q.top().h;
		long long t=q.top().t;
		q.pop();
		if(x==en)
		{
			return t;
		}
		if(vis[x])continue;
		for(auto y:v[x])
		{
			if(!vis[y.x]&&h+y.h<k)
			{
				q.push({y.x,t+y.t,h+y.h});
			}
		}
	}
	return -1;
}
int main()
{
	
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,t,h;
		scanf("%d %d %d %d",&a,&b,&t,&h);
		v[a].push_back({b,t,h});
		v[b].push_back({a,t,h});
	}
	cin>>st>>en;
	cout<<f();
}
/*
10 4 7
1 2 4 4
1 3 7 2
3 1 8 1
3 2 2 2
4 2 1 6
3 4 1 1
1 4 6 12
1 4

*/
