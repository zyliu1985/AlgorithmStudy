#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n;
char s[10];
int cnt[10];
vector<int>ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=5;j++)
			if(s[j]=='Y')
				cnt[j]++;
	}
	int maxn=0;
	for(int i=1;i<=5;i++)
		maxn=max(maxn,cnt[i]);
	for(int i=1;i<=5;i++)
		if(cnt[i]==maxn)
			ans.push_back(i);
	int len=ans.size();
	for(int i=0;i<len;i++)
	{
		printf("%d",ans[i]);
		if(i!=len-1)
			putchar(',');
	}
	return 0;
}
