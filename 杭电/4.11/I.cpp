#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
long long f[1000005];
int main(){
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		f[0] = 1;
		long long s = 0;
		int _5k = 1;
		for (int i = 1; i <= k; i++){
			_5k = (_5k * 5) % mod;
			f[i] = ((f[i-1] + s) * 21) % mod;
			s = ((s * 5) % mod + (5 * f[i-1]) % mod) % mod;
		}
		_5k = (_5k * 5) % mod;
		for (int i = k+1; i <= n+1; i++){
			f[i] = ((f[i-1] + s) * 21) % mod;
			s = ((((s * 5) % mod + (5 * f[i-1])) % mod) % mod - (f[i - k - 1] * _5k) % mod + mod) % mod;
		}
		while (f[n+1] % 21) f[n+1] += mod;
		cout << (f[n+1] / 21) % mod << '\n';
	}
	return 0;
}



