#include<bits/stdc++.h>
using namespace std;

int h[5010];
int f[5010][5010];
int ans[5010];

int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> h[i];
	memset(ans,0x3f,sizeof(ans));
	for(int i = 1;i <= n;i++)f[i][i] = 0,ans[1] = 0;;
	for(int i = 1;i < n;i++)f[i][i + 1] = abs(h[i] - h[i + 1]),ans[2] = min(ans[2],f[i][i + 1]);
	for(int l = 3;l <= n;l++)
		for(int i = 1;i + l - 1 <= n;i++)
		{
			int j = i + l - 1;
			f[i][j] = f[i + 1][j - 1] + abs(h[i] - h[j]);
			ans[l] = min(ans[l],f[i][j]);
		}
	for(int i = 1;i <= n;i++)
		cout << ans[i] << " ";
	return 0;
}
