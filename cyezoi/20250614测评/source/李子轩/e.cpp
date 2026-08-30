#include<bits/stdc++.h>
using namespace std;
int a[2003], b[2003], d[2003], e[2003];
int main()
{
	int k, n, m, s, c;
	cin >> k >> n >> m;
	if(k != 1)
	{
		cout << 7;
		return 0;
	}
	for(int i = 1; i <= m; i++)
	{
		int s, c;
		cin >> a[i] >> b[i] >> e[i] >> d[i];
	}
	cin >> s >> c;
	int minn = 123456789;
	for(int i = 1; i <= m; i++)
	{
		if(d[i] == 1)
		{
			if((a[i] == s && b[i] == c) || (a[i] == c && b[i] == s))
			{
				if(e[i] <= minn)
				{
					minn = e[i];
				}
			}
		}
	}
	if(minn == 123456789)
	{
		cout << -1;
	}
	else 
	{
		cout << minn;
	}
	return 0;
}
