#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
struct jgt
{
	int to,tm,damage;
};
const int N=2010;
vector<jgt> g[N];
int k,n,m,a,b;
int ans=2e9;
int vis[N];
void dfs(int now,int tim,int bad)
{
	if(now==b)
	{
		ans=min(ans,tim);
		return;
	}
	for(int i=0;i<g[now].size();++i)
	{
		jgt nx=g[now][i];//next
		if(!vis[nx.to]&&bad+nx.damage<k)
		{
			vis[nx.to]=1;
			dfs(nx.to,tim+nx.tm,bad+nx.damage);
			vis[nx.to]=0;
		}
	}
}
int main()
{
	cin>>k>>n>>m;
	for(int i=0;i<m;++i)
	{
		int ta,tb,t,h;
		cin>>ta>>tb>>t>>h;
		jgt temp;
		temp.to=tb;
		temp.tm=t;
		temp.damage=h;
		g[ta].push_back(temp);
		temp.to=ta;
		g[tb].push_back(temp);
	}
	cin>>a>>b;
	dfs(a,0,0);
	cout<<(ans==2e9?-1:ans)<<endl;
	return 0;
}
