#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		long long n;
		cin >> n;
		long long ans = 0;
		long long k = 1;
		while (n > 0){
			int a = n % 10;
			n /= 10;
			if (a >= 5){
				n++;
				ans = 0;
			} else {
				ans += a * k;
			}
			k *= 10;
		}
		cout << ans << endl;
	}
	return 0;
}