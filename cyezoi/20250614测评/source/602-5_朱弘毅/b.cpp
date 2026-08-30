#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[4][200001];
long long ans;
int main()
{
	//freopen("data.in","r",stdin);
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
			if(a[i][j])
			{
				int tmp=0;
				tmp+=a[i][j-1]+a[i][j+1];
				if((i&1&&j&1)||(!(i&1)&&!(j&1)))tmp+=a[i+1][j];
				else tmp+=a[i-1][j];
				ans+=3-tmp;
			}
		}
	}
	cout<<ans;
}
/*
5
1 0 1 0 1
0 0 0 0 0

7
0 0 1 1 0 1 0
0 0 1 0 1 0 0
*/
