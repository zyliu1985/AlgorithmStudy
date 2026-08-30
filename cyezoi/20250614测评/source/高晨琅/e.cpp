#include<bits/stdc++.h>
using namespace std;
int A,B,k,n,m,ans;
struct stu{
	int e,h,t;
};
struct st{
	int u,h,t;
};
queue<st> q;
vector<stu> to[2010];
void bfs()
{
	st j;
	j.h=0;
	j.t=0;
	j.u=A;
	q.push(j);
	while(!q.empty())
	{
		st l=q.front();
		q.pop();
		int uu=l.u;
		for(int i=0;i<to[uu].size();i++)
		{
			st f;
			stu v;
			v=to[uu][i];
			f.h=v.h+l.h;
			if(f.h>=k) continue;
			f.t=v.t+l.t;
			f.u=v.e;
			if(v.e==B) ans=min(ans,f.t);
			else q.push(f);
		}
	}
}
int main()
{
	ans=1000000000;
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		stu j;
		j.e=b;
		j.t=c;
		j.h=d;
		to[a].push_back(j);
		j.e=a;
		to[b].push_back(j);
	}
	cin>>A>>B;
	bfs();
	if(ans==1000000000) cout<<-1;
	else cout<<ans;
	return 0;
}
