#include<bits/stdc++.h>
using namespace std;
int g,p,a[100010],maxn;
bool vis[100010];
void dfs(int idx)
{
	for(int i=1;i<=a[idx];i++)
	{
		if(!vis[i])
		{
			maxn=max(idx,maxn);
			vis[i]=1;
			dfs(idx+1);
			vis[i]=0;
		}
	}
}
int main()
{
	cin>>g>>p;
	for(int i=1;i<=p;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<maxn;
}
