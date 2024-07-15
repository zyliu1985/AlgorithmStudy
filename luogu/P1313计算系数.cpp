#include <iostream>
#include <cmath>
using namespace std;

const int mod = 10007;
long long f[1105][1105];
long long q_pow(long long di, int up){
	if (up == 0) return 1;
	if (up == 1) return di;
	if (up % 2 == 0) return q_pow(di * di % mod, up / 2); 
	else return q_pow(di * di % mod, up / 2) * di % mod;
}
int main(){
	int a, b, k, n, m;
	cin >> a >> b >> k >> n >> m;
	for (int i = 0; i <= k; i++){
		f[i][0] = 1, f[i][i] = 1;
		for (int j = 1; j < i; j++)
			f[i][j] = (f[i-1][j] + f[i-1][j-1]) % mod;
	}
	cout << (q_pow(a, n) * q_pow(b, m) % mod * f[k][n] % mod) % mod << endl;
	return 0;
}