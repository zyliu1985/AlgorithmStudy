#include <bits/stdc++.h>
using namespace std;
long long n, cnt, minn;

long long a[5010];
int main(void)
{
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	cout << 0 << " ";//Ò»×ùÉ½
	
	for(int i = 2;i <= n;i ++)
	{
		minn = INT_MAX;
		for(int j = 1;j <= n - i + 1;j ++)
		{
			int l = j, r = l + i - 1;
			cnt = 0;
			while(l <= r)
			{
				cnt += abs(a[l] - a[r]);
				if(cnt > minn)
					break;
				l ++;
				r --;
			}
			minn = min(minn, cnt);
		}
		cout << minn << " ";
	}
	return 0;
}

/*
4
1 3 5 6


7
3 1 4 1 5 9 2
*/
