#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,a[5005],ans[5005];
bool in(int x,int y)
{
	return 1<=x&&x<=y&&y<=n;
}
void dfs(int l,int r,int x)
{
	//if(r-l+1>=4)cout<<l<<" "<<r<<" "<<x<<endl;
	ans[r-l+1]=min(x,ans[r-l+1]);
	if(in(l-1,r+1))
	{
		dfs(l-1,r+1,x+abs(a[l-1]-a[r+1]));
	}
}
int main()
{
	
	memset(ans,0x3f,sizeof(ans));
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,i,0);
	}
	for(int i=1;i<n;i++)
	{
		dfs(i,i+1,abs(a[i]-a[i+1]));
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
}
/*
7
3 1 4 1 5 9 2

4
1 3 5 6
*/
