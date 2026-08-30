#include <bits/stdc++.h>
using namespace std;
int a[3005],b[105],dp[3005][5],c[3005];
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int m;
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	if (m==0)
	{
		for (int i=1;i<=n;i++)
		{
			c[i]=a[i];
		}
		for (int i=1;i<=n;i++)
		{
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			dp[i][1]=dp[i-1][0]+c[i];
		}
		cout<<max(dp[n][0],dp[n][1])<<endl;
	}
	if (m==1)
	{
		int maxn=0;
		for (int i=0;i<=n+1;i++)
		{
			int cur=0;
			for (int j=1;j<=i;j++)
			{
				c[++cur]=a[j];
			}
			c[++cur]=b[1];
			for (int j=i+1;j<=n;j++)
			{
				c[++cur]=a[j];
			}
			for (int i=1;i<=n+1;i++)
			{
				dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
				dp[i][1]=dp[i-1][0]+c[i];
			}
			maxn=max(max(dp[n][0],dp[n][1]),maxn);
		}
		cout<<maxn<<endl;
	}
	
}
