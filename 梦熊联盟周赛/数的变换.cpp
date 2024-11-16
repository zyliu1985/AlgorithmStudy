#include <iostream>
using namespace std;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	int t;
	cin >> t;
	while (t--){
		long long n;
		bool ok = true;
		cin >> n;
		int ans = 0;
		while (n > 1){
			if (n % 2 == 0) ans++, n /= 2;
			else if (n % 3 == 0) ans += 2, n /= 3;
			else if (n % 5 == 0) ans += 3, n /= 5;
			else{
				ok = false;
				cout << -1 << endl;
				break;
			}
		}
		if (ok) cout << ans << endl;
	}
	return 0;
} 
