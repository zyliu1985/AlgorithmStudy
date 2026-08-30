#include<bits/stdc++.h>
using namespace std;
int a[3005],b[3005],c[3005],v[3005];
int n,m;

int solve1(int x)
{
	for(int i=x;i>=1;i--)
	{
		v[i]=max(a[i]+v[i+2],v[i+1]);
	}
	return v[1];
}

int solve2()
{
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i];
	}
	int ans=0;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[j]=c[j];
		}
		for(int j=n;j>=i;j--)
		{
			a[n+1]=a[n];
		}
		a[i]=b[1];
		int s1=solve1(n+1);
		ans=max(ans,s1);
	}
	return ans;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	if(m==0) cout<<solve1(n);
	if(m==1) cout<<solve2();
	return 0;
}
