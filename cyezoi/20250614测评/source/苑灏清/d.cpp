#include<bits/stdc++.h>
using namespace std;

int G, p;
int g[100009];
bool jw[100009];
int wz;
bool pd(int k)
{
	for (int i = k; i >= 1; i--)
	{
		if (jw[i] == 0)
		{
			wz = i;
			return 1;
		}
	}
	return 0;
}
int main()
{
	cin >> G >> p;
	int ans = 0;
	bool zt = 1;
	for (int i = 0; i < p; i++)
	{
		cin >> g[i];
		if (zt)
		{
			if (pd(g[i]))
			{
				jw[wz] = 1;
				ans++;
			}
			else
				zt = 0;
		}
	}
	cout << ans;
	return 0;
}
