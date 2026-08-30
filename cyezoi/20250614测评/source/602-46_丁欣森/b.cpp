#include<bits/stdc++.h>
using namespace std;
int arr[200005][2];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i][0]);
		ans+=3*arr[i][0];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i][1]);
		ans+=3*arr[i][1];
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&arr[i][0]==1&&arr[i-1][0]==1)
			ans-=2;
		if(i!=1&&arr[i][1]==1&&arr[i-1][1]==1)
			ans-=2;
		if(i%2==1&&arr[i][0]==1&&arr[i][1]==1)
			ans-=2;
	}
	printf("%d\n",ans);
	return 0;
}
