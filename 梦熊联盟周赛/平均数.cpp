#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		long long a, b, c;
		cin >> a >> b >> c;
		long long x, y;
		x = a + c;
		y = 2 * b;
		long long d = abs(x - y);
		long long ans1 = d % 3;
		long long ans2 = d / 3;
		if (ans1 == 2){
			ans1 = 1;
			ans2++;
		}
		cout << ans2 << ' ' << ans1 << endl;
	}
	return 0;
}