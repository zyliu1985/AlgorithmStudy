#include <iostream>
using namespace std;

int n, m, x, k;
long long q_pow(long long di, int up){
	if (up == 0) return 1;
	if (up == 1) return di;
	if (up % 2 == 0) return q_pow(di * di % n, up / 2); 
	else return q_pow(di * di % n, up / 2) * di % n;
}
int main(){
	cin >> n >> m >> k >> x;
	cout << (x + (m * q_pow(10, k)) % n) % n;
	return 0;
}