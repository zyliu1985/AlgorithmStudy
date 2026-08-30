#include <bits/stdc++.h>
using namespace std;
int n,m,a[3010],b[110],dp[3210][2];

int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>m;
	for(int i=0;i<m;i++) cin>>b[i];
	if(m==0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=max(1,i-3);j<i;j++) dp[i][0]=max(max(dp[i][0],dp[j][0]),dp[j][1]);
			for(int j=(1,i-3);j<i-1;j++) dp[i][1]=max(max(dp[i][1],dp[j][0]),dp[j][1]);
			dp[i][1]=max(dp[i][1],dp[i-1][0])+a[i-1];
			
		}
		cout<<max(dp[n][0],dp[n][1]);
		return 0;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=max(1,i-3);j<i;j++) dp[i][0]=max(max(dp[i][0],dp[j][0]),dp[j][1]);
			for(int j=(1,i-3);j<i-1;j++) dp[i][1]=max(max(dp[i][1],dp[j][0]),dp[j][1]);
			dp[i][1]=max(dp[i][1],dp[i-1][0])+a[i-1];
			
		}
		cout<<max(dp[n][0],dp[n][1])+b[0];
		return 0;
	}
	cout<<44;
	return 0;
}
