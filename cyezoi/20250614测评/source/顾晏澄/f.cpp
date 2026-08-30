#include <bits/stdc++.h>
using namespace std;

int a[4000],b[1000],tnt[5000];

int main()
{
	int n,m,ans = 0;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		tnt[i] = a[i];
	}
	cin >> m;
	for(int i = 0;i < m;i++)
	{
		cin >> b[i];
		tnt[n+i] = b[i];
	}
	int num = (n+m)/2;
	sort(tnt,tnt+n+m);
	for(int i = n+m;i >= num;i--)
		ans += tnt[i];
	cout << ans;
	return 0;
}
