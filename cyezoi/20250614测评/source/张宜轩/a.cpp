#include<bits/stdc++.h>
using namespace std;
char str[10];
int cnt[10];
int main()
{
	int n,i,j,m=0,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%s",str+1);
		for(j=1;j<=5;++j)
		{
			if(str[j]=='Y')
			{
				cnt[j]++;
				m=max(m,cnt[j]);
			}
		}
	}
	for(i=1;i<=5;++i)
	{
		if(cnt[i]==m)
		{
			if(flag==0)
				printf("%d",i);
			else 
				printf(",%d",i);
			flag=1;
		}
	}
	return 0;
}
