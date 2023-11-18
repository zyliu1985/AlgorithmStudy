#include <iostream>
using namespace std;

int l, r;
//long long fun(long long x){
//	long long sum = 0;
//	for (long long i = l; i*i <= x; i++){
//		if (x % i == 0){
//			if (x / i > r) continue;
//			if (i * i != x) sum += 2;
//			else sum += 1;
//		}
//	}
//	return sum;
//}
long long fun(long long x){
	int y = 2, ans = 1, t = 1;
	while (x > 0){
		if (x % y == 0){
			x /= y;
			t++;
		} else {
			ans *= t;
			while (zhi())
		}
	}
}
int main(){
	cin >> l >> r;
	long long ans = 0;
	for (long long i = l; i <= r; i++) ans += fun(i*i);
	cout << ans << endl;
	return 0;
}