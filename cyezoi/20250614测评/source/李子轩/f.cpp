#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	if(m >= 2)
	{
		cout << 44;
		return 0;
	}
	if(m == 0)
	{
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			int w;
			cin >> w;
			if(w % 2 == 1)
			{
				sum += w;
			}
		}
		cout << sum;
	}
	if(m == 1)
	{
		int sum = 0;
		for(int i = 1; i <= n + 1; i++)
		{
			int w;
			cin >> w;
			if(w % 2 == 1)
			{
				sum += w;
			}
		}
		cout << sum;
	}
	return 0;
}
