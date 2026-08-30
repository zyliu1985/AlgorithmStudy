#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long Inf=1e17+9;
const long long Mod=1e9+7;

ll n,a[19];
vector<int> vec; 

void solve()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='Y')
				a[j]++;
		}
	}
	ll ans=-Inf;
	for(int i=1;i<=5;i++)
	{
		if(a[i]>ans)
		{
			vec.clear();
			vec.push_back(i);
			ans=a[i];
		}
		else if(a[i]==ans)
			vec.push_back(i);
		else continue;
	}
	for(int i=0;i<vec.size();i++)
	{
		if(i==vec.size()-1)
			printf("%d\n",vec[i]);
		else printf("%d,",vec[i]);
	}
	return;
}

signed main()
{
	ll T=1,i=1;
	while(T--)
		solve();
	return 0;
}
