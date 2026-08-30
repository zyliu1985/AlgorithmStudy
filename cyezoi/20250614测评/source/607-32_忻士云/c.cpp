#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long Inf=1e17+9;
const long long Mod=1e9+7;

int n,sub[5009][5009],mn[100009],dp[5009][5009],a[100009];

void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			sub[i][j]=abs(a[i]-a[j]);
	fill(mn+1,mn+n+5,Inf);
	for(int i=1;i<=n;i++)
		dp[1][i]=0;
	mn[1]=0;
	for(int i=1;i<n;i++)
	{
		dp[2][i]=abs(a[i]-a[i+1]);
		mn[2]=min(mn[2],dp[2][i]);
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			dp[i][j]=dp[i-2][j+1]+sub[j][j+i-1];
			mn[i]=min(mn[i],dp[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==n)
			printf("%d\n",mn[i]);
		else printf("%d ",mn[i]);
	}
	return;
}

signed main()
{
	ll T=1,i=1;
	while(T--)
		solve();
	return 0;
}
