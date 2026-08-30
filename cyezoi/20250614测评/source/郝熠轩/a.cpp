#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[8], maxn;
vector<int> v;
char c;
signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 5; j++)
		{
			cin >> c;
			a[j] += c == 'Y';
		}
	for (int i = 1; i <= 5; i++)
	{
		if (a[i] > maxn)
		{
			maxn = a[i];
			v.clear();
		}
		if (a[i] == maxn) v.push_back(i);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i < v.size() - 1) cout << ",";
	}
	return 0;
}
