#include <iostream>
#include <cmath>
#define int long long
using namespace std;

bool zhi(int x){
	for (int i = 2; i <= sqrt(x); i++){
		if (x % i == 0) return false;
	}
	return true;
}
int gcd(int x, int y){
	if (x % y == 0) return y;
	return gcd(y, x%y);
}
int fun(int x, int y){
	int g = gcd(x, y);
	return g*(x/g)*(y/g);
}
int fun2(int x, int y, int z){
	int ans = 1;
	for (int i = 2; i <= min(x, min(y, z)); i++){
		if (!zhi(i)) continue;
		if (x % i == 0 && y % i == 0 && z % i == 0){
			ans *= i;
			x /= i;
			y /= i;
			z /= i;
			i--;
		}
	}
	for (int i = 2; i <= max(x, max(y, z)); i++){
		if (!zhi(i)) continue;
		if (x % i == 0 && y % i == 0){
			ans *= i;
			x /= i;
			y /= i;
			i--;
		} else if (x % i == 0 && z % i == 0){
			ans *= i;
			x /= i;
			z /= i;
			i--;
		} else if (y % i == 0 && z % i == 0){
			ans *= i;
			z /= i;
			y /= i;
			i--;
		}
	}
	ans *= x*y*z;
	return ans;
}
signed main(){
	int a, b, c;
	int t;
	cin >> t >> a >> b >> c;
	cout << t-(t/a+t/b+t/c-t/fun(a, b)-t/fun(b, c)-t/fun(c, a)+t/fun2(a, b, c)) << endl;
}