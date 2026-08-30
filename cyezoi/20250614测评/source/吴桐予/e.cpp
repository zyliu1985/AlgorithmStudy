#include <bits/stdc++.h>
using namespace std;
int k,n,m,A,B,ans=999999999;
int ff[2005][2005],f[2005][2005][5][1005];
void dfs(int is,int to,int tn,int kn)
{
	if(kn>=k)return;
	if(is+to>n)return;
	if(is==B)
	{
		ans=min(ans,tn);
		return;
	}
	else
	{
		if(ff[is][is+to]==1)
		for(int i=1;i<=m;++i)
		{
			dfs(is+to,to,tn+f[is][is+to][1][i],kn+f[is][is+to][2][i]);
		}
		else dfs(is,to++,tn,kn);
	}
	return;
}
int main()
{
	cin>>k>>n>>m;
	int p=0;
	for(int i=1,a,b,t,h;i<=m;++i)
	{
		cin>>a>>b>>t>>h;
		if(ff[a][b]==1)p++;
		ff[a][b]=1;
		ff[b][a]=1;
		f[a][b][1][p]=t;
		f[a][b][2][p]=h;
		f[b][a][1][p]=t;
		f[b][a][2][p]=h;
	}
	cin>>A>>B;
	dfs(A,1,0,0);
	if(ans==999999999)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
