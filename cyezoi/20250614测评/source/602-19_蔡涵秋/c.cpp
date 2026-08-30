#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 5;

int n, h[N], ans[N];

int solve1(int mid)
{
	int now = 0;
	for (int i = 1; mid - i >= 1 && mid + i <= n; i++)
	{
		int l = mid - i, r = mid + i;
		now += abs(h[l] - h[r]);
		ans[2 * i + 1] = min(ans[2 * i + 1], now);
	}
}

int solve2(int mid)
{
	int now = 0;
	for (int i = 1; mid - i + 1 >= 1 && mid + i <= n; i++)
	{
		int l = mid - i + 1, r = mid + i;
		now += abs(h[l] - h[r]);
		ans[2 * i] = min(ans[2 * i], now);
	}
}

signed main()
{
	//freopen ("datac.in", "r", stdin);
	//freopen ("datac.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	memset (ans, 0x3f, sizeof ans);
	ans[1] = 0;
	for (int mid = 1; mid <= n; mid++)
	{
		solve1(mid);
		solve2(mid);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
