#include<bits/stdc++.h>
using namespace std;
int h[5005],ans[5005];
int main()
{
	int n,tmp=0;
	memset(ans,0x3f,sizeof(ans));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	ans[1]=0;
	for(int i=1;i<=n;i++)
	{
		tmp=0;
		for(int j=i-1,k=i+1;j>=1&&k<=n;j--,k++)		
		{
			tmp+=abs(h[j]-h[k]);
			ans[k-j+1]=min(ans[k-j+1],tmp);
		}
		tmp=0;
		if(i!=1)
			for(int j=i-1,k=i;j>=1&&k<=n;j--,k++)		
			{
				tmp+=abs(h[j]-h[k]);
				ans[k-j+1]=min(ans[k-j+1],tmp);
			}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
