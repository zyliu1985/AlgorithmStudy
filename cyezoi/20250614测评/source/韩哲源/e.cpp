#include<bits/stdc++.h>
using namespace std;
struct s
{
	int t;
	int h;
};
s island[10000][10000];
int n,m,k,A,B,K,T,mi=INT_MAX;
bool f;
void fn(int x)
{
	if(K>=k) return;
	if(T>=mi) return;
	for(int i=1;i<=n;i++)
	{
		if(island[x][i].h!=0)
		{
			if(i==B)
			{
				K+=island[x][i].h;
				if(K<k)
				{
				T+=island[x][i].t;
				mi=min(mi,T);
				K-=island[x][i].h;
				T-=island[x][i].t;
				f=1;
				return;
				}
				else K-=island[x][i].h;
			}
			K+=island[x][i].h;
			T+=island[x][i].t;
			fn(i);
			K-=island[x][i].h;
			T-=island[x][i].t;
		}
	}
}
int main()
{
	cin>>k>>n>>m;
	int o1,o2,o3,o4;
	for(int i=1;i<=m;i++)
	{
		cin>>o1>>o2>>o3>>o4;
		island[o1][o2].h=o4;
		island[o1][o2].t=o3;
		island[o2][o1].h=o4;
		island[o2][o1].t=o3;
	}
	cin>>A>>B;
	fn(A);
	if(f==1)
		cout<<mi<<endl;
	else 
		cout<<-1<<endl;
	return 0;
}
