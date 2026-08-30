#include<bits/stdc++.h>
using namespace std;
int a[100010],cnt[100010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			char c;
			cin>>c;
			if(c=='Y') cnt[j]++;
		}
	}
	long long sum=*max_element(cnt+1,cnt+6);
	int ans=0;
	for(int i=1;i<=5;i++)
	{
		if(cnt[i]==sum)
		{
			if(ans==0)
			{
				cout<<i;
				ans=1;
			}
			else cout<<','<<i;
		}
	}
	return 0;
}
