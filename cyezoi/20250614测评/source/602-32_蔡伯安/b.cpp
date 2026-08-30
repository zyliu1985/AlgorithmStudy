#include<bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			ans+=3;
			if(a[i-1]==1) ans--;
			if(i%2==1&&b[i]==1) ans--;
			if(a[i+1]==1) ans--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
		{
			ans+=3;
			if(b[i-1]==1) ans--;
			if(i%2==1&&a[i]==1) ans--;
			if(b[i+1]==1) ans--;
		}
	}
	cout<<ans;
}
