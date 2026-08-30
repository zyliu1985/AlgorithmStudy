#include<bits/stdc++.h>
using namespace std;
int ans,a[10][200000];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0) continue;
			if(j%2==0)
			{
				if(a[i][j-1]+a[i][j+1]==0)
				{
					ans+=3;
					a[i][j]=0;
				}
				else if(a[i][j-1]+a[i][j+1]==1)
				{
					ans++;
					a[i][j]=0;
				}
				else if(a[i][j-1]+a[i][j+1]==2)
				{
					ans--;
					a[i][j]=0;
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1) cnt++;
		}
	}
	ans+=cnt*3;
	for(int i=1;i<=n;i++)
	{
		if(a[1][i]==1&&a[2][i]==1) ans-=2;
	}
	cout<<ans<<endl;
	return 0;
}
