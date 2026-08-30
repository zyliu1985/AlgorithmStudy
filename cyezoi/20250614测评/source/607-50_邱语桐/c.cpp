#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
ll n,h[N],f[N][N],ans[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>h[i];
	fill(ans+1,ans+1+n,1e9);
	ans[1]=0;
	for(ll i=1;i<n;i++)
	{
		f[i][i+1]=abs(h[i+1]-h[i]);
		ans[2]=min(ans[2],f[i][i+1]);
	}
	for(ll j=2;j<=n;j++)
	  for(ll i=1;i<=n-j;i++)
		{
			f[i][i+j]=f[i+1][i+j-1]+abs(h[i+j]-h[i]);
			ans[j+1]=min(ans[j+1],f[i][i+j]);
		}
	for(ll i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}

