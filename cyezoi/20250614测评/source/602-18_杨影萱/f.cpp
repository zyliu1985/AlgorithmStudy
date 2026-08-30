#include<bits/stdc++.h>
using namespace std;
int n,m,a[3003],b[102],f[2][3003];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	if(m==0)
	{
		f[1][1]=a[1];f[1][2]=a[2];
		for(int i=1;i<=n;i++)
		{
			f[1][i]=max(f[0][i-1],f[0][i-2])+a[i];
			f[0][i]=max(f[1][i-1],f[1][i-2]);
		}
		cout<<max(f[1][n],f[0][n]);
	}
	else if(m==1)
	{
		int c[n+1],ans=0;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++) c[j]=a[j];
			if(i==0)
			{
				c[0]=b[1];
				f[1][0]=c[0];f[1][1]=c[1];
				for(int j=0;j<=n;j++)
				{
					f[1][j]=max(f[0][j-1],f[0][j-2])+c[j];
					f[0][j]=max(f[1][j-1],f[1][j-2]);
				}
				ans=max(ans,max(f[1][n],f[0][n]));
			}
			else
			{
				for(int j=1;j<=i;j++) c[j-1]=c[j];
				c[i]=b[1];
				f[1][0]=c[0];f[1][1]=c[1];
				for(int j=0;j<=n;j++)
				{
					f[1][j]=max(f[0][j-1],f[0][j-2])+c[j];
					f[0][j]=max(f[1][j-1],f[1][j-2]);
				}
				ans=max(ans,max(f[1][n],f[0][n]));
			}
		}
		cout<<ans;
	}
	return 0;
}
