#include <iostream>
using namespace std;

int f[2005][2005];
int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) f[1][i] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			for (int k = j; k <= n; k += j)
				f[i+1][k] = (f[i+1][k] + f[i][j]) % 1000000007;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + f[k][i]) % 1000000007;
	cout << ans << endl;
	return 0;
}