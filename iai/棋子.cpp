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
int pow2[1000005];
long long frac[1000005];
long long C(int n, int m){
	return frac[n] * inv(frac[m]) % mod * inv(frac[n-m]) % mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	frac[0] = 1;
	for (int i = 1; i <= n; i++)
		frac[i] = (frac[i-1] * i) % mod;
	pow2[0] = 1;
	for (int i = 1; i <= n; i++)
		pow2[i] = pow2[i-1] * 2 % mod;
	long long ans = 0;
	for (int k = 0; k < n; k++)
		ans = (ans + qpow(-1, k) * C(n, k) * qpow(pow2[n-k] - 1, m) % mod) % mod;
	ans = (ans + mod) % mod;
	cout << ans << '\n';
	return 0;
}

