//200pts * 100% = 200pts
#include <bits/stdc++.h>
using namespace std;
int n, sum;
int a[2][200005];
int ci[4] = {1, -1, 0, 0};
int cj[4] = {0, 0, 1, -1};
int main()
{
	cin >> n;
	for(int i = 0; i <= 1; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j], sum += a[i][j];
	sum *= 3;
	for(int i = 0; i <= 1; i++)
		for(int j = 1; j <= n; j++)
		{
			if(!a[i][j])
				continue;
			for(int k = 0; k < 4; k++)
			{
				int ni = i + ci[k];
				int nj = j + cj[k];
				if(ni < 0 || nj < 0 || ni > 1 || nj > n)
					continue;
				if(a[ni][nj])
					sum--;
			}
		}
	cout << sum;
	return 0;
}
/*
5
1 0 1 0 1
0 0 0 0 0


7
0 0 1 1 0 1 0
0 0 1 0 1 0 0
*/
