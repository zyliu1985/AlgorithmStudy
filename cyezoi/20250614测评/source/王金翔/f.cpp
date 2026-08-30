#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=3e3+10;
int a[N],b[N],c[N],f[N];
int solve(int n)
{
	memset(f,0,sizeof f);
	f[1]=c[1];
	for(int i=2;i<=n;i++)
	{
		f[i]=max(f[i-2]+c[i],f[i-1]);
	}
	return f[n];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int m;
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	if(m==0)
	{
		for(int i=1;i<=n;i++) c[i]=a[i];
		cout<<solve(n);
	}
	else if(m==1)
	{
		int ans=0;
		for(int i=1;i<=n+1;i++)
		{
			for(int j=1;j<i;j++) c[j]=a[j];
			c[i]=b[1];
			for(int j=i+1;j<=n+1;j++) c[j]=a[j-1];
			ans=max(ans,solve(n+1));
		}
		cout<<ans;
	}
	return 0;
}

