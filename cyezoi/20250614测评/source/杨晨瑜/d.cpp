#include<bits/stdc++.h>
using namespace std;
int g,p,ans=0;
int a[2005],vis[100005]={false};
int num(int cnt)
{
	cnt=1;
	while(cnt<=g)
	{
		for(int j=1;j<=a[cnt];j++)
		{
			vis[j]=true;
			if(a[++cnt]==j) j++;
			else cnt=num(cnt); 
		}
	}
	return cnt;
}
int main()
{
	cin>>g>>p;
	for(int i=1;i<=p;i++)
	{
		cin>>a[i];
	}
	ans=max(ans,num(0));
	cout<<ans;
	return 0;
}
