#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[3005],b[105];
long long dp[2][105][2],f[2][2],ans;//i_th|throw j b_element|get/throw
long long get(int x)
{
	if(x>=m+1)return 0;
	memset(f,0,sizeof(f));
	for(int i=x;i<=m;i++)
	{
		bool tmp=i&1;
		f[tmp][0]=max(f[!tmp][0],f[!tmp][1]);
		f[tmp][1]=f[!tmp][0]+b[i];
	}
	return max(f[m&1][1],f[m&0][1]);
}
int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",b+i);
	}
	sort(b+1,b+m+1);
	
	for(int i=1;i<=n;i++)
	{
		long long max0=0,max1=0;
		bool tmp=i&1;
		for(int j=0;j<=m;j++)
		{
			dp[tmp][j][0]=max({max0,dp[!tmp][j][0],max1,dp[!tmp][j][1]});
			dp[tmp][j][1]=max({max0,dp[!tmp][j][0],max1})+a[i];
			max0=max(max0,dp[!tmp][j][0]);
			max1=max(max1,dp[!tmp][j][1]);
			//cout<<"{"<<dp[tmp][j][0]<<" "<<dp[tmp][j][1]<<"} ";
		}
	//	cout<<endl;
	}
	for(int i=0;i<=m;i++)
	{
		ans=max(ans,max(dp[n&1][i][0]+get(i+1),dp[n&1][i][1]+get(i+2)));
	//	cout<<dp[n&1][i][0]<<" "<<dp[n&1][i][1]<<endl;
	}
	cout<<ans;
}
/*
5
10 12 6 14 7
3
1 2 8

*/
