#include<bits/stdc++.h>
using namespace std;
int n,h[5019];
int fn(int x,int y)
{
	int l=y;
	int r=x+y-1;
	int cnt=0;
	while(l<=r)
	{
		cnt+=abs(h[l]-h[r]);
		l++;
		r--;
	}
	return cnt;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	cout<<0<<" ";
	for(int i=2;i<=n;i++)
	{
		int mi=INT_MAX;
		for(int j=1;j<=n-i+1;j++)
		{
			int a=fn(i,j);
			mi=min(mi,a);
		}
		cout<<mi<<" ";
	}
	return 0;
}
