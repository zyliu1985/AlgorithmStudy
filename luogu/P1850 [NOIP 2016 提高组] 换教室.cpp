#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int c[2005], d[2005];
double k[2005];
int f[305][305];
double dp[2005][2005][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(f, 0x3f, sizeof(f));
	int n, m, v, e;
	cin >> n >> m >> v >> e;
	for (int i = 1; i <= v; i++)
		f[i][i] = 0;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++)
		cin >> k[i];
	for (int i = 1; i <= e; i++){
		int a, b, w;
		cin >> a >> b >> w;
		f[a][b] = min(f[a][b], w);
		f[b][a] = min(f[b][a], w);
	}
	for (int l = 1; l <= v; l++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				f[i][j] = min(f[i][j], f[i][l] + f[l][j]);
//	for (int i = 1; i <= v; i++){
//		for (int j = 1; j <= v; j++)
//			cout << f[i][j] << ',';
//		cout << '\n';
//	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j][0] = dp[i][j][1] = 1e9;
	dp[1][0][0] = 0;
	dp[1][1][1] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= min(i, m); j++){
			dp[i][j][0] = min(dp[i-1][j][0] + f[c[i-1]][c[i]], dp[i-1][j][1] + k[i-1] * f[d[i-1]][c[i]]
			                                                                 + (1.0 - k[i-1]) * f[c[i-1]][c[i]]);
			if (j > 0){
				dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-1][0] + k[i] * f[c[i-1]][d[i]]
				                                               + (1.0 - k[i]) * f[c[i-1]][c[i]]);
				
				dp[i][j][1] = min(dp[i-1][j-1][0] + k[i] * f[c[i-1]][d[i]]
				                                  + (1.0 - k[i]) * f[c[i-1]][c[i]]
								, dp[i-1][j-1][1] + k[i] * k[i-1] * f[d[i-1]][d[i]]
				                                  + k[i] * (1.0 - k[i-1]) * f[c[i-1]][d[i]]
												  + (1.0 - k[i]) * k[i-1] * f[d[i-1]][c[i]]
												  + (1.0 - k[i]) * (1.0 - k[i-1]) * f[c[i-1]][c[i]]);
			}
//			cout << "(" << i << ", " << j << ")  0: " << dp[i][j][0] << "     1: " << dp[i][j][1] << '\n';
		}
	double ans = 1e9;
	for (int i = 0; i <= m; i++){
		ans = min(ans, min(dp[n][i][0], dp[n][i][1]));
	}
	printf("%.2lf", ans);
	return 0;
}

