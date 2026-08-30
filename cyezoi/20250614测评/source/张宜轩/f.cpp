#include<bits/stdc++.h>
using namespace std;
int arr[100005],b[100005],arr1[10005];
int main()
{
	int i,j,m,n,ans=0,ans1=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&arr[i]);
	scanf("%d",&m);
	for(i=1;i<=m;++i)
		scanf("%d",&b[i]);
	if(m==0)
	{
		for(i=1;i<=n;i+=2)
			ans+=arr[i];
		for(i=2;i<=n;i+=2)
			ans1+=arr[i];
		printf("%d",max(ans,ans1));
		return 0;
	}
	if(m==1)
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=i;++j)
				arr1[j]=arr[i];
			arr1[i+1]=b[1];
			for(j=i+2;j<=n;++j)
				arr1[j]=arr[j-1];
			for(i=1;i<=n;i+=2)
				ans+=arr1[i];
			for(i=2;i<=n;i+=2)
				ans1+=arr1[i];
			printf("%d",max(ans,ans1));
		}
	}
	return 0;
}
