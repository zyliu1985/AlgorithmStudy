#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, t;
bool a[N], b[N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i])
		{
			if (a[i - 1]) t++;
			else t += 3;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		if (b[i])
		{
			if (b[i - 1]) t++;
			else t += 3;
			if (i % 2 && a[i]) t -= 2;
		}
	}
	cout << t;
	
}
