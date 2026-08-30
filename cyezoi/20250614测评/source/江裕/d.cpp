#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, p;
int a[N], vis[N];

int main()
{
	cin >> n >> p;
	for(int i = 1; i <= p; i ++ )
	{
		cin >> a[i];
	}
	for(int i = 1; i <= p; i ++ )
	{
		bool flag = true;
		for(int j = a[i]; j >= 1; j -- )
		{
			if(!vis[j])
			{
				vis[j] = 1;
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout << i - 1 << "\n";
			return 0;
		}
	}
	cout << n << "\n";
	return 0;
}
