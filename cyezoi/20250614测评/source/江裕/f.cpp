#include <bits/stdc++.h>

using namespace std;

int n, m;
deque<int> b;
int a[3005], p1 = 1, p2 = 1, ans;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	cin >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int u;
		cin >> u;
		b.push_back(u);
	}
	sort(b.begin(), b.end());
	int flag = 1;
	while(p1 <= n || !b.empty())
	{
		if(flag)
		{
			if(p1 == n + 1)
			{
				ans += b[b.size() - 1];
				b.pop_back();
				flag ^= 1;
				continue;
			}
			if(b.empty())
			{
				ans += a[p1];
				p1 ++ ;
				flag ^= 1;
				continue;
			}
			if(a[p1] >= b[b.size() - 1])
			{
				ans += a[p1];
				p1 ++ ;
			}
			else
			{
				ans += b[b.size() - 1];
				b.pop_back();
			}
		}
		if(!flag)
		{
			if(p1 == n + 1)
			{
				b.pop_front();
				flag ^= 1;
				continue;
			}
			if(b.empty())
			{
				p1 ++ ;
				flag ^= 1;
				continue;
			}
			if(a[p1] < b[0])
			{
				p1 ++ ;
			}
			else
			{
				b.pop_front();
			}
		}
		flag ^= 1;
	}
	cout << ans << "\n";
	return 0;
}
