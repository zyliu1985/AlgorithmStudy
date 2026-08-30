#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=20004;
vector<pair<ll,ll>> e[N];
ll k,n,m,A,B;
ll dst[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>k>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll u,v,t,h;
		cin>>u>>v>>t>>h;
		if(h==0)
		{
			e[u].push_back(make_pair(v,t));
			e[v].push_back(make_pair(u,t));
		}
	}
	cin>>A>>B;
	fill(dst+1,dst+1+n,1e9);
	queue<ll> q;
	q.push(A);
	dst[A]=0;
	while(!q.empty())
	{
		ll u=q.front();q.pop();
		for(auto x:e[u])
		{
			ll v=x.first,t=x.second;
			if(dst[v]>dst[u]+t)
			{
				dst[v]=dst[u]+t;
				q.push(v);
			}
		}
	}
	if(dst[B]!=1e9)
	  cout<<dst[B];
	else cout<<-1;
	return 0;
}

