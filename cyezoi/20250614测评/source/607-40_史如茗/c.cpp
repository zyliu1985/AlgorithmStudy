#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5005;
int n, l, r, h[N];
LL mn[N], t;
int main()
{
	memset(mn, 0x3f, sizeof(mn));
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++)
	{
		l = r = i, t = 0;
		while (l && r <= n)
		{
			t += abs(h[l] - h[r]);
			mn[r - l + 1] = min(mn[r - l + 1], t);
			l--, r++;
		}
		l = i, r = i + 1, t = 0;
		while (l && r <= n)
		{
			t += abs(h[l] - h[r]);
			mn[r - l + 1] = min(mn[r - l + 1], t);
			l--, r++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << mn[i] << " ";
	}
}
