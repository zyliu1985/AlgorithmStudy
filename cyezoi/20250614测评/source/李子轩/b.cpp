#include<bits/stdc++.h>
using namespace std;
bool a[710000];
int main()
{
	int n, w;
	cin >> n;
	int e;
	if(n % 2 == 0)
	{
		e = 2 + 7 * n / 2;
	}
	else
	{
		e = 5 + 7 * n / 2;
	}
	for(int i = 1; i <= e; i++) a[i] = 1;
	for(int i = 1; i <= 2; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> w;
			if(w == 1)
			{
				if(i == 1)
				{
					a[2 * j - 1] = 1 - a[2 * j - 1];
					a[2 * j] = 1 - a[2 * j];
					a[2 * j + 1] = 1 - a[2 * j + 1];
				}
				else 
				{
					if(j % 2 == 1)
					{
						a[2 * j] = 1 - a[2 * j];
						a[2 * j + 2 * n - j / 2] = 1 - a[2 * j + 2 * n - j / 2];
						a[2 * j + 2 * n - j / 2 + 1] = 1 - a[2 * j + 2 * n - j / 2 + 1];
					}
					else
					{
						a[2 * n + 2 * j - j / 2] = 1 - a[2 * j + 2 * n - j / 2];
						a[2 * n + 2 * j - j / 2 + 1] = 1 - a[2 * j + 2 * n - j / 2 + 1];
						a[2 * n + 2 * j - j / 2 + 2] = 1 - a[2 * j + 2 * n - j / 2 + 2];
					}
				}
			}
		}
	}
	int sum = 0;
	for(int i = 1; i <= e; i++)
	{
		if(!a[i])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
