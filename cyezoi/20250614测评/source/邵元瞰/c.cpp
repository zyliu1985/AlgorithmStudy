#include <bits/stdc++.h>
using namespace std;
int a[5005],sum[5005];
int main()
{
	int n;
	cin>>n;
	if (n<=300)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for (int i=1;i<=n;i++)
		{
			int minn=1e9;
			for (int j=1;j<=n-i+1;j++)
			{
				int sum=0;
				for (int k=0;k<=(i-1)/2;k++)
				{
					sum+=abs(a[j+k]-a[i+j-1-k]);
				}
				minn=min(minn,sum);
			}
			cout<<minn<<" ";
		}
		cout<<endl;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		for (int i=1;i<=n;i++)
		{
			int minn=1e9;
			for (int j=1;j<=n-i+1;j++)
			{
				minn=min(minn,sum[i+j-1]-sum[i+j-1-(i-1)/2-1]-sum[j+(i-1)/2]+sum[j-1]);
			}
			cout<<minn<<" ";
		}
		cout<<endl;
	}
}
