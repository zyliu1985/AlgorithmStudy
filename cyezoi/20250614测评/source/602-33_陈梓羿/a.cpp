#include<bits/stdc++.h>
using namespace std;
int num[10];
int main()
{
	int n,maxn=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			char s;
			cin>>s;
			if(s=='Y')
			{
				num[j]++;
				maxn=max(maxn,num[j]);
			}
		}
	}
	bool flag=0;
	for(int i=1;i<=5;i++)
	{
		if(num[i]==maxn)
		{
			if(flag==1)
			{
				cout<<",";
			}
			cout<<i;
			flag=1;
		}
	}
	return 0;
}
