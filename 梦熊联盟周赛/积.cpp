#include <iostream>
using namespace std;

const int mod = 998244353;
int mi(int di, int up){
	long long re = 1;
	for (int i = 1; i <= up; i++)
		re = re * di % mod;
	return re;
}
int q_mi(int di, int up){
	long long re = di, x = 1;
	if (up < 3) return mi(di, up);
	while (up > x){
		if (up / x >= 3) x *= 3;
		else return (re * q_mi(di, up - x)) % mod;
		re = mi(re, 3);
	}
	return re;
}
int main(){
	int n;
	cin >> n;
	long long ans = 1;
	for (int i = 2; i <= n; i++)
		ans = ans * q_mi(i, i) % mod;
	cout << ans << endl;
	return 0;
}