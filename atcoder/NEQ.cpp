#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
long long frac[500005];
int qpow(long long x, int up){
	if (up == 0) return 1;
	if (up & 1) return qpow(x * x % mod, up / 2) * x % mod;
	else return qpow(x * x % mod, up / 2);
}
int inv(long long x){
	return qpow(x, mod-2);
}
int A(int x, int y){ // x >= y
	return frac[x] * inv(frac[x-y]) % mod;
}
int C(int x, int y){ // x >= y
	return A(x, y) * 1ll * inv(frac[y]) % mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	frac[0] = 1;
	for (int i = 1; i <= m; i++)
		frac[i] = frac[i-1] * i % mod;
	long long ans = 0;
	for (int k = 0; k <= n; k++){
		if (k & 1){
			ans = (ans - ((C(n, k) * 1ll * A(m, k) % mod) * (A(m-k, n-k) * 1ll * A(m-k, n-k) % mod) % mod) % mod + mod) % mod;
		} else {
			ans = (ans + ((C(n, k) * 1ll * A(m, k) % mod) * (A(m-k, n-k) * 1ll * A(m-k, n-k) % mod) % mod) % mod) % mod;
		}
//		cout << (C(n, k) * 1ll * A(m, k) % mod) * (A(m-k, n-k) * 1ll * A(m-k, n-k)) % mod << '\n';
	}
	cout << ans << '\n';
	return 0;
}

