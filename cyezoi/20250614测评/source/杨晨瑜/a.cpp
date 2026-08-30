#include<bits/stdc++.h>
using namespace std;
int n,maxn,ans[6],cnt;
struct node
{
	int data,num;
}y[6];
bool cmp(node a,node b)
{
	return a.num>b.num;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			char s;
			cin>>s;
			if(s=='Y') y[j].data=j,y[j].num++;
		}
	}
	sort(y+1,y+5+1,cmp);
	maxn=y[1].num;
	for(int i=1;i<=5;i++)
	{
		if(y[i].num==maxn) ans[++cnt]=y[i].data;
	}
	sort(ans+1,ans+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		if(i==1) cout<<ans[i];
		else cout<<","<<ans[i];
	}
	return 0;
}
