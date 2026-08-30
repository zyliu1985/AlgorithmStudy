#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200005], b[200005], ans;
signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans += 3 * a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		ans += 3 * b[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] && a[i + 1]) ans -= 2;
		if (b[i] && b[i + 1]) ans -= 2;
	}
	for (int i = 1; i <= n; i += 2) if (a[i] && b[i]) ans -= 2;
	cout << ans;
	return 0;
}
