#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],b[110],ans,sum[3010];
bool vis[3010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	if(m==0)
	{
		sum[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			sum[i]=max(sum[i-2]+a[i],sum[i-1]);
		}
		cout<<sum[n];
	}
	else if(m==1)
	{
		sum[1]=a[1];
		for(int i=0;i<=n+1;i++)
		{
			for(int j=1;j<=i;j++)
			{
				sum[j]=max(sum[j-2]+a[j],sum[j-1]);
			}
			if(i==0) sum[i]=b[1];
			if(i>=1) sum[i+1]=max(sum[i]+a[i+1],sum[i-1]+b[1]);
			if(i>=1) sum[i+2]=max(sum[i+1],sum[i-1]+b[1]+a[i+2]);
			for(int j=i+3;j<=n;j++)
			{
				sum[j]=max(sum[j-2]+a[j],sum[j-1]);
			}
		}
		cout<<sum[n];
	}
	else 
	{
		for(int i=n+1;i<=n+m;i++)
		{
			a[i]=b[i-n];
		}
		sort(a+1,a+n+m+1);
		for(int i=n+m;i>=(n+m)/2+1;i--)
		{
			ans+=a[i];
		}
		cout<<ans;
	}
}
