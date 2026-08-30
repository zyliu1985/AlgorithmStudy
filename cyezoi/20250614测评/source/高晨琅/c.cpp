#include<bits/stdc++.h>
using namespace std;
int a[5010],x[201][5001],ma[201];
int main()
{
	memset(ma,0x3f,sizeof(ma));
	int n,laz=0,lo;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n%200==0) lo=n/200;
	else lo=n/200+1;
	for(int l=1;l<=lo;l++)
	{
		memset(ma,0x3f,sizeof(ma));
		for(int i=1;i<=200;i++)
		{
			for(int j=1;j<=n-i+1;j++)
			{
				if(i==1) x[i][j]=x[199][j+1];
				else if(i==2) x[i][j]=x[200][j+1]+abs(a[j+laz*200]-a[j+1+laz*200]);
				else
				{
					x[i][j]=x[i-2][j+1]+abs(a[j+laz*200]-a[j+i-1+laz*200]);
				}
				ma[i]=min(ma[i],x[i][j]);
			}
		}
		for(int i=1;i<=min(n,200);i++) cout<<ma[i]<<' ';
		n-=200;
		laz++;
	}
	return 0;
}
