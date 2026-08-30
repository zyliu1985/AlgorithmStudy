#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[100005], b[100005], l, r, mid, ans;
bool check(int x)
{
	for (int i = 1; i <= x; i++) b[i] = a[i];
	sort(b + 1, b + x + 1);
	for (int i = 1; i <= x; i++) if (b[i] < i) return 0;
	return 1;
}
signed main()
{
	cin >> n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	l = 1, r = n;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}
