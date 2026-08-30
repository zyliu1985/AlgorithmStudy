#include<bits/stdc++.h>
using namespace std;

int a[3010];
int b[110];
int f[3010][110][110][3];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i];
	int m;
	cin >> m;
	for(int i = 1;i <= m;i++)cin >> b[i];
	sort(b + 1,b + n + 1,cmp);
	f[0][0][1][2] = b[1];
	for(int i = 2;i <= (m + 1) / 2;i++)
		f[0][i - 1][i][2] = f[0][i - 2][i - 1][2] + b[i];
	for(int i = 1;i <= n;i++)
		for(int j = 0;j <= m;j++)
			for(int k = 0;k <= m;k++)
			{
				if(j + k > m)continue;
				f[i][j][k][0] = max(f[i][j][k][0],f[i - 1][j][k][0]);
				f[i][j][k][0] = max(f[i][j][k][0],f[i - 1][j][k][1]);
				f[i][j][k][0] = max(f[i][j][k][0],f[i - 1][j][k][2]);
				f[i][j][k][1] = max(f[i][j][k][1],f[i - 1][j][k][0] + a[i]);
				if(j > 0)
				{
					f[i][j][k][1] = max(f[i][j][k][1],f[i - 1][j - 1][k][1] + a[i]);
					f[i][j][k][1] = max(f[i][j][k][1],f[i - 1][j - 1][k][2] + a[i]);
				}
				if(k > 0)
				{
					f[i][j][k][2] = max(f[i][j][k][2],f[i][j][k - 1][0] + b[k]);
					if(j > 0)
					{
						f[i][j][k][2] = max(f[i][j][k][2],f[i][j - 1][k - 1][1] + b[k]);
						f[i][j][k][2] = max(f[i][j][k][2],f[i][j - 1][k - 1][2] + b[k]);
					}
				}
			}
	int ans = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 0;j <= m;j++)
			for(int k = 0;k <= m;k++)
				for(int q = 0;q < 3;q++)
					ans = max(ans,f[i][j][k][q]);
	cout << ans;
	return 0;
}
