#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main()
{
	int n;
	cin>>n;
	int ans=0,cnt=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==1 && a[i-1]==1)	ans++;
		if (a[i]==1)	cnt++;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>b[i];
		if (b[i]==1 && b[i-1]==1)	ans++;
		if (i%2==1 && b[i]==1 && a[i]==1)	ans++;
		if (b[i]==1)	cnt++;
	}
	cout<<cnt*3-ans*2<<endl;
}
