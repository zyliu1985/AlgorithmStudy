#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 911471543;
long long qpow(long long x, int up){
	if (up == 0) return 1;
	if (up & 1) return qpow(x * x % mod, up / 2) * x % mod;
	else return qpow(x * x % mod, up / 2);
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	cout << qpow(2, n) * qpow(n, mod-2) % mod << '\n';
	return 0;
}

