#include <iostream>
using namespace std;

const int mod = 1e9+7;
long long f[100005];
int main(){
	int n;
	cin >> n;
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = (f[i-1] + f[i-2] * 2) % mod;
	cout << f[n] << endl;
	return 0;
}