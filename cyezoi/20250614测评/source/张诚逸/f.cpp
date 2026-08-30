#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

int n, m, a[6006], b[3006], ans, cur;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> b[i];
	for(int i = n + 1; i <= n + m; i++) a[i] = b[i - n];
	int maxn = 0, maxi = 0;
	do
	{
		maxn = 0;
		maxi = 0;
		for(int i = 1; i <= n + m; i++)
		{
			if(a[i + 1] != -1 && a[i - 1] != -1)
			{
				if(maxn < a[i])
				{
					maxi = i;
					maxn = a[i];
				}
			}
		}
		ans += maxn;
		a[maxi] = -1;
	}
	while(maxi != 0);
	cout << ans << endl;
	return 0;
}

