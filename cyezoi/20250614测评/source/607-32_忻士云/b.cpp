#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long Inf=1e17+9;
const long long Mod=1e9+7;

ll c,dp[2][200009];
bool flg[2][200009];

void solve()
{
	scanf("%lld",&c);
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=c;j++)
		{
			ll x;
			scanf("%lld",&x);
			if(x==0)
				flg[i][j]=false;
			else flg[i][j]=true;
		}
	}
	dp[1][1]=(flg[1][1])*3;
	for(int i=2;i<=c;i++)
	{
		if(flg[1][i]==false)
		{
			dp[1][i]=dp[1][i-1];
			continue;
		}
		if(flg[1][i-1]==true)
			dp[1][i]=dp[1][i-1]+1;
		else dp[1][i]=dp[1][i-1]+3;
	}
	if(flg[2][1]==true)
	{
		if(flg[1][1]==true)
			dp[2][1]=dp[1][c]+1;
		else dp[2][1]=dp[1][c]+3;
	}
	else dp[2][1]=dp[1][c];
	for(int i=2;i<=c;i++)
	{
		if(flg[2][i]==false)
		{
			dp[2][i]=dp[2][i-1];
			continue;
		}
		if(!(i%2))
		{
			if(flg[2][i-1]==true)
				dp[2][i]=dp[2][i-1]+1;
			else dp[2][i]=dp[2][i-1]+3;
		}
		else
		{
			if(flg[2][i-1]==true && flg[1][i]==true)
				dp[2][i]=dp[2][i-1]-1;
			else if(flg[2][i-1]==true && flg[1][i]==false)
				dp[2][i]=dp[2][i-1]+1;
			else if(flg[2][i-1]==false && flg[1][i]==true)
				dp[2][i]=dp[2][i-1]+1;
			else dp[2][i]=dp[2][i-1]+3;
		}
	}
	printf("%lld\n",dp[2][c]);
	return;
}

signed main()
{
	ll T=1,i=1;
	while(T--)
		solve();
	return 0;
}
