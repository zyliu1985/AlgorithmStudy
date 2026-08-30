#include<bits/stdc++.h>
using namespace std;
int a[5][200005];
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1) ans+=3;
		}
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			{
//				cout<<i<<" "<<j<<"\n";
				if(j%2==0)
				{
					if(a[i][j-1]==1) ans--;
					if(a[i][j+1]==1) ans--;
				}
				if(j%2==1)
				{
					if(a[i][j-1]==1) ans--;
					if(a[i][j+1]==1) ans--;
					if(a[(i%2)+1][j]==1) ans--;
				}
			}
		}
	}
	cout<<ans;
	
	return 0;
}
