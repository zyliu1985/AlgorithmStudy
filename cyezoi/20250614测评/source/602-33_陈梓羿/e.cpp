#include<bits/stdc++.h>
using namespace std;
int k,n,m,A,B;
bool vis[2005];

struct node{
	int t,h,a,b;
}r[20005];

int ans=0x3f3f3f3f;

void f(int st,int kl,int ta)
{
	if(st==B) 
	{
		ans=min(ans,ta);
	}
	for(int i=1;i<=2*m;i++)
	{
		if(r[i].a==st && kl>r[i].h && !vis[r[i].b])
		{
//			cout<<i<<" ";
			vis[r[i].b]=1;
			f(r[i].b,kl-r[i].h,ta+r[i].t);
			vis[r[i].b]=0;
		}
	}
	return;
}

int main()
{
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,t,h;
		cin>>a>>b>>t>>h;
		r[i].a=a;
		r[i].b=b;
		r[i].t=t;
		r[i].h=h;
		r[i+m].b=a;
		r[i+m].a=b;
		r[i+m].t=t;
		r[i+m].h=h;
	}
	cin>>A>>B;
	vis[A]=1;
	f(A,k,0);
	cout<<ans;
	return 0;
}
