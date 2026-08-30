#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, ans;
bool a[2][N];
signed main()
{
	cin >> n;
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		if (a[0][i] == 1)
		{
			ans += 3;
			if (a[0][i - 1] == 1)
				ans--;
			if (a[0][i + 1] == 1)
				ans--;
			if (a[1][i] == 1)
				ans--;
		}
	for (int i = 1; i <= n; i++)
		if (a[1][i] == 1)
		{
			ans += 3;
			if (a[1][i - 1] == 1)
				ans--;
			if (a[1][i + 1] == 1)
				ans--;
			if (a[0][i] == 1)
				ans--;
		}
	cout << ans;
}
