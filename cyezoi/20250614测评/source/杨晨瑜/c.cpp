#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int h[5005];
ll num(int l,int r,int m)
{
	ll ans=0;
	for(int i=l;i<=l+m/2-1;i++)
	{
		ans+=max(h[i],h[r-i+l])-min(h[i],h[r-i+l]);
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1) cout<<0<<" ";
		else if(i==n) cout<<num(1,n,n)<<" ";
		else
		{
			ll minn=0x3f3f;
			for(int l=1;l<=n-i+1;l++)
			{
				minn=min(minn,num(l,l+i-1,i));
//				cout<<l<<" "<<l+i-1<<" ";
			}
			cout<<minn<<" ";
		}
	}
	return 0;
}
