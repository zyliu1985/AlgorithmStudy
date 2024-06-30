#include <iostream>
#include <time.h>
using namespace std;

const int mod = 1e9+7;
int f[305][305][305];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) f[0][0][i] = 1;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= n; j++){
			for (int k = 0; k <= j; k++)
				f[i][j][k] = (f[i][j][k-1] + f[i-1][j-k][k]) % mod;
			for (int k = j+1; k <= n; k++)
				f[i][j][k] = f[i][j][k-1];
		}
	cout << f[m][n][n] << endl;
	return 0;
}