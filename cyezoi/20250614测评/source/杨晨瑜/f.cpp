#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[3005],b[105],c[4005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	if(m==0)
	{
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i+=2) cnt1+=a[i];
		for(int i=2;i<=n;i+=2) cnt2+=a[i];
		ans=max(cnt1,cnt2);
		cout<<ans;
	}
	else if(m==1)
	{
		for(int i=1;i<=n+1;i++)
		{
			for(int j=1;j<=n+1;j++)
			{
				if(j==i) c[j]=b[1];
				else if(j<i) c[j]=a[j];
				else c[j]=a[j-1];
			}
			int cnt1=0,cnt2=0;
			for(int i=1;i<=n+1;i+=2) cnt1+=c[i];
			for(int i=2;i<=n+1;i+=2) cnt2+=c[i];
			ans=max(ans,max(cnt1,cnt2));
		}
		cout<<ans;
	}
	else cout<<44;
	return 0;
}
