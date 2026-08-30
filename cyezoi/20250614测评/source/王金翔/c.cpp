#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e3+10;
ll a[N],f[N][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,ans=1e18;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][i]=0;
		if(i>1)
		{
			f[i-1][i]=abs(a[i-1]-a[i]);
			ans=min(ans,f[i-1][i]);
		}
	}
	cout<<0<<" ";
	if(n>1) cout<<ans<<" ";
	for(int l=3;l<=n;l++)
	{
		ans=1e18;
		for(int i=1,j=l;j<=n;i++,j++)
		{
			f[i][j]=f[i+1][j-1]+abs(a[i]-a[j]);
			ans=min(ans,f[i][j]);
		}
		cout<<ans<<" ";
	}
	return 0;
}
