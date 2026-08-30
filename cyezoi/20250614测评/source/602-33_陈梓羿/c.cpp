#include<bits/stdc++.h>
using namespace std;
int a[5005][5005];
int h[5005];
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	for(int i=1;i<=n;i++)
	{
		int len=min(2*i-2,2*n-2*i+1)+1;
//		cout<<len<<" ";
		a[i][1]=0;
		a[i][0]=0;
		for(int j=2;j<=len;j++)
		{
			if(j%2==1) a[i][j]=a[i][j-2]+abs(h[i+(j-1)/2]-h[i-(j-1)/2]);
			if(j%2==0) a[i][j]=a[i][j-2]+abs(h[i+j/2-1]-h[i-j/2]);
		}
	}
	int st=1,en=n+1;
	for(int i=1;i<=n;i++)
	{
		int minn=0x3f3f3f3f;
		if(i%2==1) en--;
		else st++;
		for(int j=st;j<=en;j++)
		{
			minn=min(minn,a[j][i]);
		}
		cout<<minn<<" ";
	}
	return 0;
}
