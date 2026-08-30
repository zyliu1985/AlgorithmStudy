#include<bits/stdc++.h>
using namespace std;
char sz[1005][1005];
int ans[10005],flag=1;
int main()
{
	int n,i,sz_l,s=0,maxv=INT_MIN,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%s",sz[i]+1);
	sz_l=strlen(sz[1]+1);
//	printf("sz_l=%d\n",sz_l);	
	for(i=1;i<=sz_l;i++)
	{
		s=0;
		for(j=1;j<=n;j++)
		{
			if(sz[j][i]=='Y')
				s++;
		}
		ans[++ans[0]]=s;
	}
	for(i=1;i<=ans[0];i++)
		maxv=max(ans[i],maxv);
//	for(i=1;i<=ans[0];i++)
//		printf("%d ",ans[i]);
	for(i=1;i<=ans[0];i++)
	{
		if(maxv==ans[i])
		{
			if(flag)
				printf("%d",i),flag=0;
			else
				printf(",%d",i);
		}
	}
	return 0;
}
/*
5
YY..Y
.YY.Y
.Y.Y.
.YY.Y
Y...Y
*/
