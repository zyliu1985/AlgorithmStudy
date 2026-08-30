#include<bits/stdc++.h>
using namespace std;
int a[5][200010],f;
int main ()
{
	int n;
	cin>>n;
	for (int i=1;i<=2;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j]==1)
			{
				f++;
			}
		}
	}
	f*=3;
	for (int i=1;i<=2;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if ((a[i][j+1]==1)&&(a[i][j]==1))
			{
				f-=2;
			}
			if ((a[i+1][j]==1)&&(j%2==1)&&(a[i][j]==1))
			{
				f-=2;
			}
		}
	}
	cout<<f;
	return 0;
}
