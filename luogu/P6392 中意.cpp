#include <iostream>
#include <algorithm>
using namespace std;

const long long mod = 998344353;
long long qpow(long long x, long long up){
	if (up == 0) return 1;
	if (up & 1) return qpow(x * x % mod, up / 2) * x % mod;
	else return qpow(x * x % mod, up / 2); 
}
long long Qpow(long long x, long long up){
	if (up == 0) return 1;
	if (up & 1) return Qpow(x * x % 25, up / 2) * x % 25;
	else return Qpow(x * x % 25, up / 2); 
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	long long a;
	cin >> a;
	string x;
	cin >> x;
	long long b = 0, B = 0;
	for (int i = 0; i < x.size(); i++)
		b = (b * 10 + x[i] - '0') % mod, B = (B * 10 + x[i] - '0') % 25;
	int added = 25 - (B * Qpow(2, a+2)) % 25;
	if (added == 25) added = 0;
	cout << added << '\n';
	for (int i = 0; i < 25; i++)
		cout << ((b * qpow(2, a+2)) % mod + i) * 4 % mod << '\n';
	return 0;
}



