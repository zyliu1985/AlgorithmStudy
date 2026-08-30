#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 9999973;
long long f[105][105][105];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	f[0][m][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= m - j; k++){
				f[i][j][k] = (f[i][j][k] + f[i-1][j][k]) % mod;
				f[i][j][k] = (f[i][j][k] + (j+1) * f[i-1][j+1][k-1] % mod) % mod;
				f[i][j][k] = (f[i][j][k] + (k+1) * f[i-1][j][k+1] % mod) % mod;
				f[i][j][k] = (f[i][j][k] + ((j+2) * (j+1) / 2 % mod) * f[i-1][j+2][k-2] % mod) % mod;
				f[i][j][k] = (f[i][j][k] + ((j+1) * k % mod) * f[i-1][j+1][k] % mod) % mod;
				f[i][j][k] = (f[i][j][k] + ((k+2) * (k+1) / 2 % mod) * f[i-1][j][k+2] % mod) % mod;
			}
	int ans = 0;
	for (int j = 0; j <= m; j++)
		for (int k = 0; k <= m - j; k++)
			ans = (ans + f[n][j][k]) % mod;
	cout << ans << '\n';
	return 0;
}



