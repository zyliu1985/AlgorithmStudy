#include <iostream>
using namespace std;

long long x, y;
void exgcd(int a, int b){
	if (b == 0){ // 得到了a_nx + 0 = gcd(a, b)，就是a_nx = gcd(a, b)，而a_n = gcd(a, b)，那么x = 1
		x = 1;
		y = 0; // y无所谓
		return;
	}
	exgcd(b, a % b);
	int t = x;
	x = y;
	y = t - (a / b) * y;
}
int main(){
	int a, b;
	cin >> a >> b;
	exgcd(a, b);
	x = (x % b + b) % b;
	cout << x << endl;
	return 0;
}