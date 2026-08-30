#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long Inf=1e17+9;
const long long Mod=1e9+7;

ll n,m;
ll a[100009],dp[100009];

void solve()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i==1)
			dp[i]=a[i];
		if(i==2)
			dp[i]=max(a[i],a[i-1]);
		dp[i]=max(dp[i-1],dp[i-2]+a[i]);
	}
	printf("%lld\n",dp[n]);
}

signed main()
{
	ll T=1,i=1;
	while(T--)
		solve();
	return 0;
}
