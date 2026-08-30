#include<bits/stdc++.h>
using namespace std;
int n,cnt[6],ma;
string a[100019];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		for(int j=0;j<5;j++)
		{
			if(a[i][j]=='Y') cnt[j+1]++;
		}
	}
	for(int i=0;i<5;i++)
	{
		if(cnt[i]>=ma) ma=cnt[i];
	}
	bool f=0;
	for(int i=1;i<=5;i++)
	{
		if(cnt[i]==ma) 
		{
		if(f==1) cout<<',';
		f=1;
		cout<<i;
		}
	}
	return 0;
}
