#include<bits/stdc++.h>
using namespace std;
int cnt[7];
char s[7];
int main()
{
	int n,tmp,flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		if(s[1]=='Y')
			cnt[1]++;
		if(s[2]=='Y')
			cnt[2]++;
		if(s[3]=='Y')
			cnt[3]++;
		if(s[4]=='Y')
			cnt[4]++;
		if(s[5]=='Y')
			cnt[5]++;
	}
	tmp=max(max(cnt[1],cnt[2]),max(max(cnt[3],cnt[4]),cnt[5]));
	for(int i=1;i<=5;i++)
	{
		if(cnt[i]!=tmp)
			continue;
		if(flag==0)
		{
			flag=1;
			printf("%d",i);
		}
		else
			printf(",%d",i);
	}
	return 0;
}
