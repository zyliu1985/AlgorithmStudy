#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int c[1000005];
int main()
{
	int n,m,i,j,k=1,ans=0,l=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=1,j=m;i<=m;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+1+m);
	for(i=1;i<=n+m;i++)
	{
		if(a[l]>=b[j]&&k<=j&&l<=n)
		{
			c[i]=a[l];
			c[i+1]=b[k];
			k++,i++,l++;
		}
		else if(a[l]<b[j]&&j<=m&&l<=n)
			c[i]=b[j],j--;
	}
//	for(i=1;i<=n+m;i++)
//		printf("%d ",c[i]);
//	printf("\n");
	for(i=1;i<=n+m;i+=2)
		ans+=c[i];
	printf("%d",ans);
	return 0;
}
/*
5
10
12
6
14
7
3
1
8
2
*/
