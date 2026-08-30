#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[7],ans,cnt,maxn;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			char op;
			cin>>op;
			a[j]+=(op=='Y');
		}
	}
	maxn=*max_element(a+1,a+6);
	ans=count(a+1,a+6,maxn);
	for(int i=1;i<=5;i++)
	{
		if(a[i]==maxn)
		{
			cout<<i;
			cnt++;
			if(cnt!=ans)cout<<",";
		}
	}
}
/*
3
YY.Y.
...Y.
.YYY.

5
YY..Y
.YY.Y
.Y.Y.
.YY.Y
Y...Y
*/
