#include <bits/stdc++.h>
using namespace std;
int ac[2005];
int nowa[2005][2005];
struct node
{
	int b,t,h;
};
vector<node> a[2005];
int main()
{
	int k,n,m;
	cin>>k>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			nowa[i][j]=1e9;
		}
	}
	for (int i=1;i<=m;i++)
	{
		int p,q,r,s;
		cin>>p>>q>>r>>s;
		node temp1;
		temp1.b=q;
		temp1.t=r;
		temp1.h=s;
		node temp2;
		temp2.b=p;
		temp2.t=r;
		temp2.h=s;
		a[p].push_back(temp1);
		a[q].push_back(temp2);
		if (s==0)
		{
			nowa[p][q]=r;
			nowa[q][p]=r;
		}
	}
	int fr,to;
	cin>>fr>>to;
	for (int i=1;i<=n;i++)
	{
		ac[i]=1e9;
	}
	for (int i=0;i<a[fr].size();i++)
	{
		if (a[fr][i].h==0)	{ac[a[fr][i].b]=a[fr][i].t;}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=n;k++)
			{
				ac[j]=min(ac[j],ac[k]+nowa[k][j]);
			}
		}
	}
	if (ac[to]!=1e9)	cout<<ac[to]<<endl;
	else	cout<<-1<<endl;
}
