#include <bits/stdc++.h>
using namespace std;
int n,a[5][200005],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=2;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=2;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(a[i][j]==1)
			{
				if(a[i-1][j]==1||a[i][j-1]==1)
				{
					if(a[i-1][j]==1&&a[i][j-1]==0&&j%2==1)
					{
						ans++;
					}
					else if(a[i-1][j]==1&&a[i][j-1]==0&&j%2==1)
					{
						ans+=3;
					}
					else if(a[i-1][j]==0&&a[i][j-1]==1)
					{
						ans++;
					}
					else if(a[i-1][j]==1&&a[i][j-1]==1&&j%2==1)
					{
						ans--;
					}
					else if(a[i-1][j]==1&&a[i][j-1]==1&&j%2==0)
					{
						ans++;
					}
				}
				else ans+=3;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
