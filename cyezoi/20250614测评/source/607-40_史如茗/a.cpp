#include <bits/stdc++.h>
using namespace std;
int n, t[10], mx;
char c[10];
bool f;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c + 1;
		for (int j = 1; j <= 5; j++)
		{
			t[j] += (c[j] == 'Y');
			mx = max(mx, t[j]);
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (t[i] >= mx)
		{
			if (f)
			{
				cout << ",";
			}
			cout << i;
			f = true;
		}
	}
}
