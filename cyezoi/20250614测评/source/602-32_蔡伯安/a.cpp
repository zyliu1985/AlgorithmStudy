#include<bits/stdc++.h>
using namespace std;
int n,a[10],maxn,sum;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			char x;
			cin>>x;
			if(x=='Y') a[j]++;
		}
	}
	for(int i=1;i<=5;i++) maxn=max(maxn,a[i]);
	for(int i=1;i<=5;i++)
	{
		if(maxn==a[i])
		{
			if(sum>0) cout<<',';
			cout<<i;
			sum++;
		}
	}
}
