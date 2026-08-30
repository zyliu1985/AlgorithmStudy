#include<bits/stdc++.h>
using namespace std;
int n;
struct NODE{int d,p;}a[10];
bool cmp(NODE x,NODE y)
{
	if(x.p==y.p) return x.d<y.d;
	return x.p>y.p;
}
int main()
{
	cin>>n;
	for(int i=1;i<=5;i++) a[i].d=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			char c;cin>>c;
			if(c=='Y') a[j].p++;
		}
	}
	sort(a+1,a+6,cmp);
//	for(int i=1;i<=5;i++) cout<<a[i].d<<' '<<a[i].p<<'\n';
	cout<<a[1].d;
	for(int i=2;i<=5;i++)
		if(a[i].p==a[1].p) cout<<','<<a[i].d;
	return 0;
}
