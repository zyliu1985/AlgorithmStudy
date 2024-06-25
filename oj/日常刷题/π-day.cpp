#include <iostream>
using namespace std;

int f[255][255][255]; // f[i][j][k]表示有i个人分j块派，第一人分到k块派
int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) f[1][i][i] = 1;
	for (int i = 2; i <= k; i++)
		for (int j = 1; j <= n; j++){
			int maxo = j / i; // maxo表示第一人最多可以分到多少派，等于0时表示无解
			for (int l = j-maxo; l <= j-1; l++)
				for (int m = j-l; m <= l / (i-1); m++)
					f[i][j][j-l] += f[i-1][l][m];
		}
	int ans = 0;
	for (int i = 1; i <= n / k; i++) ans += f[k][n][i];
	cout << ans << endl;
	return 0;
}