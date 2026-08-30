#include<bits/stdc++.h>
using namespace std;
int arr[5005];
int main()
{
	int i,j,ans=0,n,k,m,l;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&arr[i]);
	printf("0 ");
	for(i=1;i<n;++i)
	{
		m=INT_MAX;
		for(j=1;j<=n-i;++j)
		{
			ans=0;
			l=j;
			for(k=l+i;l<=k;k--,l++)
				ans=ans+abs(arr[k]-arr[l]);
			m=min(m,ans);
		}
		printf("%d ",m);
	}
	return 0;
}
