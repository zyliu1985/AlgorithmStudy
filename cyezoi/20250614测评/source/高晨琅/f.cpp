#include<bits/stdc++.h>
using namespace std;
int ans,n,m,a[100010],b[100010],c[100010],dp[100010];
void d()
{
	dp[1]=c[1];
	for(int i=1;i<=n+m;i++)
	{
		dp[i]=max(dp[i-2],dp[i-3])+c[i];
	}
	ans=max(ans,dp[n+m-1]);
	ans=max(ans,dp[n+m]);
}
void dfs(int ca,int cb)
{
	if(ca>=n)
	{
		for(int i=1;i<=m-cb;i++) c[i+ca+cb]=b[i];
		d();
		return ;
	}
	if(cb>=m)
	{
		for(int i=1;i<=m-ca;i++) c[i+ca+cb]=a[i];
		d();
		return ;
	}
	c[ca+cb+1]=a[ca+1];
	dfs(ca+1,cb);
	c[ca+cb+1]=b[cb+1];
	dfs(ca,cb+1);
	c[ca+cb+1]=0;
	return ;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
