#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005;
ll n,a[10],ans[10],t=0;
char ch[N][10];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(ll i=1;i<=n;i++)
	  for(ll j=1;j<=5;j++)
		{
			cin>>ch[i][j];
		}
	for(ll i=1;i<=5;i++)
	  for(ll j=1;j<=n;j++)
		{
			a[i]+=(ch[j][i]=='Y');
		}
	ll mx=*max_element(a+1,a+6);
	for(ll i=1;i<=5;i++)
	{
		if(a[i]==mx)ans[++t]=i;
	}
	for(ll i=1;i<=t;i++)
	{
		cout<<ans[i];
		if(i<t)cout<<",";
	}
	return 0;
}

