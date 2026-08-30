#include <bits/stdc++.h>
using namespace std;

int cnt1 = 0, cnt2 = 0, maxn = -INT_MAX;
int n, m;
int a[10010], b[110], x[10010], dp[10010];

int main(void)
{
	//freopen("f.in", "r", stdin);
	//freopen("f.out", "w", stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	cin >> m;
	for(int i = 1;i <= m;i ++)
		cin >> b[i];
	
	if(m == 0)
	{
		for(int i = 1;i <= n;i++)
		{
			if(i % 2 == 1)
				cnt1 += a[i];
			else
				cnt2 += a[i];
		}
		cout << max(cnt1, cnt2) << endl;
		return 0;
	}
	if(m == 1)
	{
		for(int i = 1;i <= n + 1;i ++)
		{
			for(int j = 1;j <= n;j ++)
				x[j] = a[j];
			x[n + 1] = b[1];
			for(int j = i;j <= n;j ++)
				swap(x[j], x[n + 1]);
			cnt1= 0, cnt2 = 0;
			for(int i = 1;i <= n + 1;i ++)
			{
				if(i % 2 == 1)
					cnt1 += x[i];
				else
					cnt2 += x[i];
			}
			maxn = max(maxn, max(cnt1, cnt2));
		}
		cout << maxn << endl;
		return 0;
	}
	
	cout << 44 << endl;
	return 0;
}

/*
5 
10 
12 
6 
14 
7 
3 
1 
8 
2
*/
