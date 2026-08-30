#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
int a[N],ans[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			char c;
			cin>>c;
			if(c=='Y') a[j]++;
		}
	}
	int cnt=0;
	for(int i=1;i<=5;i++)
	{
		if(a[i]>a[ans[cnt]])
		{
			cnt=0;
			ans[++cnt]=i;
		}
		else if(a[i]==a[ans[cnt]])
		{
			ans[++cnt]=i;
		}
	}
	if(cnt==0)
	{
		cout<<"1,2,3,4,5";
	}
	else
	{
		cout<<ans[1];
		for(int i=2;i<=cnt;i++) cout<<','<<ans[i];
	}
	return 0;
}
