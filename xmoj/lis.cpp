#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
long long f[205][205][205];
int main(){
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	f[1][0][1] = 1;
	f[1][1][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n; k++){
				f[i+1][j+1][k] = (f[i+1][j+1][k] + f[i][j][k]) % mod;
				f[i+1][j][max(j, k) + 1] = (f[i+1][j][max(j, k) + 1] + f[i][j][k]) % mod;
			}
	long long ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			ans = (ans + f[n][i][j] * max(i, j)) % mod;
	cout << ans << '\n';
	return 0;
}

