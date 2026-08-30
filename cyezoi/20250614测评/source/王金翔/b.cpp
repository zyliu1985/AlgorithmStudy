#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
int n;
ll ans=0,a[2][N],vis[2][N],ud[2][N],l[2][N],r[2][N];
void dfs(int x,int y)
{
	vis[x][y]=1;
	ans+=3;
	if(y%2&&a[1-x][y])
	{
		if(!ud[x][y])
		{
			ans-=2;
			ud[x][y]=ud[1-x][y]=1;
		}
		if(!vis[1-x][y]) dfs(1-x,y);
	}
	if(y>1&&a[x][y-1])
	{
		if(!l[x][y])
		{
			ans-=2;
			l[x][y]=r[x][y-1]=1;
		}
		if(!vis[x][y-1]) dfs(x,y-1);
	}
	if(y<n&&a[x][y+1])
	{
		if(!r[x][y])
		{
			ans-=2;
			r[x][y]=l[x][y+1]=1;
		}
		if(!vis[x][y+1]) dfs(x,y+1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[0][i];
	for(int i=1;i<=n;i++) cin>>a[1][i];
	for(int i=0;i<=1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(vis[i][j]==0&&a[i][j]) dfs(i,j);
		}
	}
	cout<<ans;
	return 0;
}
