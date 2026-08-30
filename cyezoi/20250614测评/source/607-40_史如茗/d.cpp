#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, x, ans;
int f[N];
int find(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	return f[x] = find(f[x]);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	while (m--)
	{
		cin >> x;
		if (!find(x))
		{
			break;
		}
		f[find(x)] = find(x) - 1;
		find(x);
		ans++;
	}
	cout << ans;
}
