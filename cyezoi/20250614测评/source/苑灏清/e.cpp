#include<bits/stdc++.h>
using namespace std;

int k, n, m;
struct lx
{
	int a, b, t, h;
}a[10009];
int f, e;

bool cmp(lx x, lx y)
{
	return x.h < y.h;
}

int dp[10009][209];

int main()
{
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].a >> a[i].b >> a[i].t >> a[i].h;
		if (a[i].a > a[i].b) swap(a[i].a, a[i].b);
	}
	cin >> f >> e;
	for (int i = f - 1; i <= e; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 1; i <= k; i++)
	{
		dp[f][i] = 0;
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= k; i++)
	{
		for (int wz = 1; wz <= m; wz++)
		{
			if (a[wz].h > i) break;
			dp[a[wz].b][i] = min(dp[a[wz].b][i - 1], a[wz].t + dp[a[wz].a][i]);
			
		}
	}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= k; i++)
	{
		ans = min(dp[e][i], ans);
//		cout << dp[e][i] << endl;
	}
	cout << ans;
	return 0;
}
