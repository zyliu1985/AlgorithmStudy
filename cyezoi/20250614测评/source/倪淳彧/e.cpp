#include <bits/stdc++.h>
using namespace std;
int k,n,m;
struct stu
{
	int st,en,tm,dmg;
}a[10001];
bool cmp(stu x,stu y)
{
	return x.tm<y.tm;
}
struct dat
{
	int go,t,d;
};
vector<dat>G[2001];
int vis[2001][2001];
int ss,ee,ans=1e9;

void dfs(int u,int time,int damage)
{
	if(u==ee){ans=min(ans,time);return ;}
	for(dat v:G[u])
	{
		if(damage+v.d>=k)continue;
		if(vis[u][v.go]>v.d)
		{
			vis[u][v.go]=vis[v.go][u]=v.d;
			dfs(v.go,time+v.t,damage+v.d);
		}
	}
}

int main()
{
	cin >> k >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int s,e,ti,da;
		cin >> s >> e >> ti >> da;
		a[i].st=s;
		a[i].en=e;
		a[i].tm=ti;
		a[i].dmg=da;
	}
	sort(a+1,a+m+1,cmp);
	for(int i = 1; i <= m; i++)
	{
		G[a[i].st].push_back({a[i].en,a[i].tm,a[i].dmg});
		G[a[i].en].push_back({a[i].st,a[i].tm,a[i].dmg});
	}
	for(int i = 1; i <= 2000; i++)for(int j = 1; j <= 2000; j++)vis[i][j]=1e9;
	cin >> ss >> ee;
	dfs(ss,0,0);
	if(ans==1e9)ans=-1;
	cout << ans;
	return 0;
}
