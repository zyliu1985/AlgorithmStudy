#include <iostream>
#include <algorithm>
using namespace std;

long long t, s;
void exgcd(int x, int y){
	if (y == 0){
		t = 1;
		s = 0;
		return;
	}
	exgcd(y, x % y);
	int temp = t;
	t = s;
	s = temp - (x / y) * s;
}
int gcd(int x, int y){
	if (x % y == 0) return y;
	return gcd(y, x % y);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	int d = a - b;
	int gd = gcd(x, y);
	if (d % gd == 0){
		x /= gd;
		y /= gd;
		d /= gd;
	} else {
		cout << "Impossible\n";
		return 0;
	}
	// 先求y关于x的逆元
	exgcd(y, x);
	t = (t % x + x) % x;
//	cout << t << '\n'; 
	t = t * ((d % x + x) % x) % x;
	cout << b + t * y * gd << '\n';
	return 0;
}

