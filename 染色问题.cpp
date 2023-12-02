#include <iostream>
#define int long long
using namespace std;

signed main(){
	int n, m;
	cin >> n >> m;
	int t = m;
	m--;
	n--;
	int ans = 1;
	while (n > 0){
		if (n & 1) ans = ans*m;
		m = m*m;
		n >>= 1;
		ans %= 1000000007;
	}
	cout << ans*t << endl;
	return 0;
}