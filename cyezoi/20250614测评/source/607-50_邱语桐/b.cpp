#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200005;
ll n,a[3][N],sum;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=1;i<=2;i++)
	  for(ll j=1;j<=n;j++)
		cin>>a[i][j];
	for(ll i=1;i<=2;i++)
	  for(ll j=1;j<=n;j++)
		sum+=a[i][j]*3;
	for(ll i=1;i<=2;i++)
	  for(ll j=1;j<n;j++)
		if(a[i][j]==1&&a[i][j+1]==1)
		  sum-=2;
	for(ll i=1;i<=n;i+=2)
	  if(a[1][i]==1&&a[2][i]==1)
		sum-=2;
	cout<<sum;
	return 0;
}

