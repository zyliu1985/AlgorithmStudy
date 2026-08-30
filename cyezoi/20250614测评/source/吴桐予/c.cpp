#include <bits/stdc++.h>
using namespace std;
int n,ans,as=99999999,h[5005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>h[i];
	}
	for(int i=1;i<=n;++i)
	{
		if(i==1)cout<<0<<" ";
		else
		{
			as=999999999;
			for(int j=1;j<=n-i+1;++j)
			{
				for(int k=1;k<=i/2;++k)
				{
					ans+=abs(h[j+k-1]-h[j+i-k]);
				}
				as=min(as,ans);
				ans=0;
			}
			cout<<as<<" ";
		}
	}
	return 0;
}
