#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005;
ll G,P,g[N],f[N];
bool p[N];
signed main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>G>>P;
	for(ll i=1;i<=G;i++)f[i]=i,p[i]=0;
	ll i;
	for(i=1;i<=P;i++)
	{
		cin>>g[i];
		while(p[f[g[i]]]==1)
		  f[g[i]]=f[f[g[i]]];
		if(f[g[i]]==0)break;
		p[f[g[i]]]=1;
		f[g[i]]--;
	}
	cout<<i-1;
	return 0;
}

