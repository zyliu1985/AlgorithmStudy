#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int b[20];

bool huiwen(long long x) {
	int cnt = 0;
	while (x > 0){
		b[++cnt] = x % 10;
		x /= 10;
	}
	for (int i = 1; i <= cnt / 2; i++)
		if (b[i] != b[cnt - i + 1])
			return false;
	return true;
}
long long pow3(long long x){
	return x * x * x;
}
int main(){
	freopen("cube.in", "r", stdin);
	freopen("cube.out", "w", stdout); 
	long long n, ans;
	cin >> n;
	for (int i = 1; pow3(i) <= n; i++)
		if (huiwen(pow3(i)))
			ans = pow3(i);
	cout << ans << '\n';
	return 0;
}
