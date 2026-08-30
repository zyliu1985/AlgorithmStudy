#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[3][N];
int b[3][N];
int main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1)
			{
				sum+=3;
			}
		}
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			{
				if(a[i][j+1]==1&&a[i+1][j+1]==1&&a[i][j+2]==1&&a[i][j+3]==1&&a[i+1][j+2]==1&&a[i+1][j+3]==1&&b[i][j+1]==0&&b[i+1][j]==0&&b[i][j+2]==0&&b[i+1][j+2]==0)
				{
					sum-=6;
					b[i][j+3]=2;
					b[i+1][j+3]=2;
					b[i][j+2]=2;
					b[i+1][j+2]=2;
				}
				if(a[i+1][j]==1&&b[i+1][j]!=1)
				{
					sum-=2;
					b[i+1][j]=1;
				}
				if(a[i][j+1]==1&&b[i][j+1]!=1)
				{
					sum-=2;
					b[i][j+1]=1;
				}
			}
		}
	}
	cout<<sum;	
}
