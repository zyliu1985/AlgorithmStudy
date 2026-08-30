#include<bits/stdc++.h>
using namespace std;
int f[3005][2],arr[3005];
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&m);
	if(m==0)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][0]=max(f[i-1][0],f[i-1][1]);
			f[i][1]=f[i-1][0]+arr[i];
		}
		printf("%d\n",max(f[n][0],f[n][1]));
	}
	else if(m==1)
	{
		int ans=0;
		scanf("%d",&arr[n+1]);
		for(int j=n;j>=0;j--)
		{
			for(int i=1;i<=n+1;i++)
			{
				f[i][0]=max(f[i-1][0],f[i-1][1]);
				f[i][1]=f[i-1][0]+arr[i];
			}
			ans=max(ans,max(f[n+1][0],f[n+1][1]));
			swap(arr[j],arr[j+1]);
		}
		printf("%d\n",ans);
		
	}
	return 0;
}
