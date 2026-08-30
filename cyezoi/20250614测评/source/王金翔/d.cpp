#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
int a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		while(x&&a[x]) x--;
		if(x) a[x]=1;
		else
		{
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}
