#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
int c2(int x){
	int re = 0;
	while (!(x & 1)){
		re++;
		x >>= 1;
	}
	return re;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		long long sum1 = 0, sum2 = 0;
		for (int i = 1; i <= n; i++){
			long long a;
			cin >> a;
			sum1 = (sum1 + a) % mod;
			sum2 = (sum2 + (a * a) % mod) % mod;
		}
		int ans1;
		int tt = ((sum1 * sum1) % mod - sum2 + mod) % mod;
		if (tt & 1)
			ans1 = (tt + mod) / 2;
		else
			ans1 = tt / 2;
		long long mul = n, last2 = n-1;
		for (long long i = n - 1; i >= 2; i--){
			if (last2 > 2 * c2(i)){
				mul = (mul * ((i * i / (1 << c2(i)) / (1 << c2(i))) % mod)) % mod;
				last2 -= 2 * c2(i);
			} else {
				mul = (mul * ((i * i / (1 << last2)) % mod)) % mod;
				last2 = 0;
			}
		}
		cout << ans1 << ' ' << mul << '\n';
		
	}
	return 0;
}



