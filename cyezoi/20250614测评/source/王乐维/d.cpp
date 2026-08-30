#include <bits/stdc++.h>
using namespace std;

int ans = 0, n, G;
int g[100010], d[100010];

int main(void)
{
	//freopen("d.in", "r", stdin);
	//freopen("d.out", "w", stdout);
	
	cin >> G >> n;
	
	for(int i = 1;i <= n;i ++)
		cin >> g[i];
		
	for(int i = 1;i <= 100001;i ++)
		d[i] = 1;
	
	for(int i = 1;i <= n;i ++)
	{
		
		bool fg = false;
		for(int j = g[i];j >= 1;j --)
		{
			if(d[j] > 0)
			{
				fg = true;
				d[j] --;
				ans ++;
				break;				
			}
		}
		if(!fg)
			break;
	}
	
	cout << ans << endl;
	return 0;
}

/*
4
3
4
1
1

4
6
2
2
3
3
4
4
*/
