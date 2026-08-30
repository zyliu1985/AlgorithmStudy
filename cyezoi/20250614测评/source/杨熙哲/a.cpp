#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char a[N][6];
int b[N][6];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='Y')
			{
				b[i][j]=1;
			}
			else b[i][j]=0;
		}
	}
	int maxn=0;
	for(int i=1;i<=5;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			sum+=a[j][i];
		}
		maxn=max(maxn,sum);
	}
	int cnt=0;
	for(int i=1;i<=5;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			sum+=a[j][i];
		}
		if(sum==maxn&&cnt==0)
		{
			cout<<i;
			cnt++;
		}
		else if(sum==maxn&&cnt!=0)
		{
			cout<<","<<i;
		}
	}
}
