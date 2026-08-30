#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long Inf=1e17+9;
const long long Mod=1e9+7;

ll g,p,mx[100009],fa[100009];

ll find(ll x)
{
	if(fa[x]==x)
		return fa[x];
	return fa[x]=find(fa[x]);
}

void unite(ll a,ll b)
{
	fa[a]=b;
	return;
}

void solve()
{
	scanf("%lld %lld",&g,&p);
	for(int i=0;i<=g;i++)
		fa[i]=i;
	for(int i=1;i<=p;i++)
	{
		ll x;
		scanf("%lld",&x);
		if(find(x)==0)
		{
			printf("%lld\n",i-1);
			return;
		}
		else unite(find(x),find(x)-1);
	}
	printf("%lld\n",p);
}

signed main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	ll T=1,i=1;
	while(T--)
		solve();
	return 0;
}
