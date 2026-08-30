#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7; 
int qpow(long long x, int up){
	if (up == 0) return 1;
	if (up & 1) return qpow(x * x % mod, up / 2) * x % mod;
	else return qpow(x * x % mod, up / 2);
}
long long inv(int x){
	return qpow(x, mod - 2);
}
long long frac[1000005];
long long C(int n, int m){
	return (frac[n] * inv(frac[m]) % mod) * inv(frac[n-m]) % mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	frac[0] = 1;
	for (int i = 1; i <= m; i++)
		frac[i] = (frac[i-1] * i) % mod;
	long long ans = 0;
	for (int k = 0; k <= m; k++){
//		cout << m << ' ' << k << ':' << C(m, k) << ' ' << qpow(-1, k) * C(m, k) * qpow(m - k, n) << '\n';
		ans += qpow(-1, k) * C(m, k) * qpow(m - k, n) % mod;
		ans = (ans + mod) % mod;
	}
	cout << ans * inv(frac[m]) % mod << '\n';
	return 0;
}

