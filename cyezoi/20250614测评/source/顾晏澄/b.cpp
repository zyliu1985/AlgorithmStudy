#include <bits/stdc++.h>
using namespace std;

bool a[2][200000];

int main()
{
	int c,ans = 0;
	cin >> c;
	for(int i = 0;i < 2;i++)
	{
		for(int j = 0;j < c;j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 1)
			{
				ans += 3;
				if(j > 0)
				{
					if(a[i][j-1] == 1)
						ans -= 2;
				}
				if(i > 0)
				{
					if(a[i-1][j] == 1 && j % 2 == 0)
						ans -= 2;
				}
			}		
		}
	}
	cout << ans;
	return 0;
}
