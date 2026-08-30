#include <bits/stdc++.h>
using namespace std;
long long minvis[210][2010];
vector<long long> g[2010];
long long n,m,k;
long long ms[2010][2010];
long long t[2010][2010];
void dfs(long long u,long long time,long long h){
	if(h>=k)
		return ;
	if(time>=minvis[h][u])
		return ;
	minvis[h][u]=time;
	for(long long i=0;i<g[u].size( );i++){
		long long v=g[u][i];
		dfs(v,time+t[u][v],h+ms[u][v]);
	}
}
int main( ){
	cin>>k>>n>>m;
	for(long long i=0;i<m;i++){
		long long u,v,h,tt;
		scanf("%lld%lld%lld%lld",&u,&v,&tt,&h);
		g[u].push_back(v);
		g[v].push_back(u);
		ms[u][v]=h;
		ms[v][u]=h;
		t[u][v]=tt;
		t[v][u]=tt;
	}
	for(int i=0;i<=k;i++)
		for(int j=0;j<=n;j++)
			minvis[i][j]=1000000000;
	long long x,y;
	cin>>x>>y;
	dfs(x,0,0);
	long long minn=1000000000;
	for(int i=0;i<k;i++)
		minn=min(minn,minvis[i][y]);
	if(minn==1000000000)
		cout<<"-1";
	else
		cout<<minn;
	return 0;
}
