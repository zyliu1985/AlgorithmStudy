#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans[5010],sum[5010];
int main()
{
	memset(ans,0x3f3f3f3f,sizeof(ans));
	ans[1]=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	if(n<=300)
	{
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=n-i+1;j++)
			{
				int num=0;
				for(int k=1;k<=i/2;k++)
				{
					num+=abs(a[j+k-1]-a[j+i-k]);
				}
				ans[i]=min(ans[i],num);
			}
		}
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=n-i+1;j++)
			{
				ans[i]=min(ans[i],sum[j+i-1]-sum[j+i-i/2-1]-sum[j+i/2-1]+sum[j-1]);
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}
