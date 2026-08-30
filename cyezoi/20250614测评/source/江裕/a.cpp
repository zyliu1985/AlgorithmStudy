#include <bits/stdc++.h>

using namespace std;

int n, ren[10];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		for(int i = 1; i <= 5; i ++ )
		{
			char c;
			cin >> c;
			ren[i] += c == 'Y';
		}
	}
	int maxn = 0;
	for(int i = 1; i <= 5; i ++ ) maxn = max(maxn, ren[i]);
	bool flag = false;
	for(int i = 1; i <= 5; i ++ )
	{
		if(ren[i] == maxn)
		{
			if(flag)cout << ",";
			cout << i;
			flag = true;
		}
	}
	return 0;
}
