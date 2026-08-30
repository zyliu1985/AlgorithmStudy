#include<bits/stdc++.h>
using namespace std;
int cnt1[100005];
int main()
{
	int i,j,m,n,a;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&a);
		for(j=a;j>0;--j)
		{
			if(cnt1[j]==0)
			{
				cnt1[j]=1;
				break;
			}
		}	
		if(j==0)
		{
			printf("%d",i-1);
			return 0;
		}
	}
	return 0;
}
