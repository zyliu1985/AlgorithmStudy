#include <bits/stdc++.h>
using namespace std;
int c, ans = 0;
int a[10][200010];
int main(void)
{
	
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	
	cin >> c;
	
	for(int i = 1;i <= 2;i ++)
		for(int j = 1;j <= c;j ++)
			cin >> a[i][j];
	
	a[1][c + 1] = -1;
	a[2][c + 1] = -1;
	
	for(int i = 1;i <= 2;i ++)
		for(int j = 1;j <= c;j ++)
		{
			int cnt = 3;
			if(a[i][j] == 1 && i == 1)
			{
				if(j % 2 == 0)//倒三角形
				{
					if(j - 1 > 0)
						if(a[i][j - 1] == 1)
							cnt --;
					if(j + 1 <= c)
						if(a[i][j + 1] == 1)
							cnt --;
					ans += cnt;
				}
				if(j % 2 == 1)//正三角形
				{
					if(j - 1 > 0)
						if(a[i][j - 1] == 1)
							cnt --;
					if(j + 1 <= c)
						if(a[i][j + 1] == 1)
							cnt --;
					if(a[i + 1][j] == 1)
						cnt --;
					ans += cnt;
				}
				
			}
			if(a[i][j] == 1 && i == 2)
			{
				if(j % 2 == 0)//倒三角形
				{
					if(j - 1 > 0)
						if(a[i][j - 1] == 1)
							cnt --;
					if(j + 1 <= c)
						if(a[i][j + 1] == 1)
							cnt --;
					ans += cnt;
				}
				if(j % 2 == 1)//正三角形
				{
					if(j - 1 > 0)
						if(a[i][j - 1] == 1)
							cnt --;
					if(j + 1 <= c)
						if(a[i][j + 1] == 1)
							cnt --;
					if(a[i - 1][j] == 1)
						cnt --;
					ans += cnt;
				}	
			}
		}
	cout << ans << endl; 
	return 0;
}


/*
7
0 0 1 1 0 1 0
0 0 1 0 1 0 0

5
1 0 1 0 1
0 0 0 0 0
*/
