#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3e3 + 5;
int n, m, a[N], b[N], x;
LL f[N][1 << 10][2], mx;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	if (m == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			f[i][0][0] = max(f[i - 1][0][1], f[i - 1][0][0]);
			f[i][0][1] = f[i - 1][0][0] + a[i];
		}
		cout << max(f[n][0][0], f[n][0][1]);
	}
	else if (m == 1)
	{
		cin >> x;
		for (int i = 1; i <= n; i++)
		{
			f[i][0][0] = max(f[i - 1][0][1], f[i - 1][0][0]);
			f[i][0][1] = f[i - 1][0][0] + a[i];
			f[i][1][0] = max(max(f[i - 1][1][1], f[i - 1][1][0]), f[i][0][1]);
			f[i][1][1] = max(f[i - 1][1][0] + a[i], f[i][0][0] + x);
		}
		cout << max(max(f[n][0][0], f[n][0][1]), max(f[n][1][0], f[n][1][1]));
	}
	else
	{
		for (int i = 1; i <= m; i++)
		{
			cin >> b[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < (1 << m); j++)
			{
				f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);
				f[i][j][1] = f[i - 1][j][0] + a[i];
				for (int k = 0; k < m; k++)
				{
					if (j & (1 << k))
					{
						f[i][j][0] = max(f[i][j][0], max(f[i][j - (1 << k)][0], f[i][j - (1 << k)][1]));
						f[i][j][1] = max(f[i][j][1], f[i][j - (1 << k)][0] + b[k + 1]);
					}
				}
				mx = max(f[i][j][0], f[i][j][1]);
			}
		}
		cout << mx;
	}
}

