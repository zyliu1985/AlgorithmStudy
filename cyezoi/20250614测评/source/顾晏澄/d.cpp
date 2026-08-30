#include <bits/stdc++.h>
using namespace std;

int a[100000];
bool b[100000];

int main()
{
	bool is_sd;
	int g,p,ans = 0;
	cin >> g;
	cin >> p;
	for(int i = 0;i < p;i++)
	{
		cin >> a[i];
		for(int j = min(a[i],g);j > 0;j--)
		{
			is_sd = 0;
			if(b[j] == 0)
			{
				b[j] = 1;
				is_sd = 1;
				break;
			}
		}
		if(is_sd == 0)
			break;
		ans ++;
	}
	cout << ans;
	return 0;
}
