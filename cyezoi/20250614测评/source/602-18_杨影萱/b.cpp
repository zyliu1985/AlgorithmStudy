#include<bits/stdc++.h>
using namespace std;
int n,a[4][200005],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			ans+=a[i][j]*3;
		}
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			{
				if(a[i][j+1]==1) ans--;
				if(a[i][j-1]==1) ans--;
				if(a[i+1][j]==1) ans--;
				if(a[i-1][j]==1) ans--;
			}
		}
	} 
	cout<<ans;
	return 0;
}
