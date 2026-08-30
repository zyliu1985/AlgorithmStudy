#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		long long m = n / 2;
		if (m & 1) cout << (2 * (((1 + m) / 2 * m) % mod)) % mod << '\n';
		else cout << (2 * ((1 + m) * (m / 2) % mod)) % mod << '\n';
	}
	return 0;
}


