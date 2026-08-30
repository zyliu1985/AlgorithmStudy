#include <bits/stdc++.h>
using namespace std;
int n,ans[10],cnt,k;
char a;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=5;++j)
		{
			cin>>a;
			if(a=='Y')ans[j]++;
		}
	}
	for(int i=1;i<=5;++i)
		cnt=max(cnt,ans[i]);
	for(int i=1;i<=5;++i)
	{
		if(ans[i]==cnt)k++;
	}
	for(int i=1;i<=5;++i)
	{
		if(k!=0)
		{
			if(ans[i]==cnt)
			{
				if(k==1)cout<<i;
				else cout<<i<<",";
				k--;
			}
		}
	}
	return 0;
}
