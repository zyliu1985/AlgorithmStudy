#include<bits/stdc++.h>
using namespace std;
int n,a[5003];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<0<<' ';
	for(int i=2;i<=n;i++)
	{
		int ans=2147483647;
		for(int j=1;j<=n-i+1;j++)
		{
			int t=0;
			for(int k=j;k<=j+i/2-1;k++)
			{
				t+=abs(a[k]-a[j*2+i-k-1]);
			}
			ans=min(ans,t);
			if(ans==0) break;
		}
		cout<<ans<<' ';
	}
	return 0;
}
