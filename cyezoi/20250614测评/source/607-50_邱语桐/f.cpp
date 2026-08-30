#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3003;
ll n,m,a[N],b[N],s1,s2;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i%2==0)s2+=a[i];
		else s1+=a[i];
	}
	for(ll i=1;i<=m;i++)cin>>b[i];
	cout<<max(s1,s2);
	return 0;
}

