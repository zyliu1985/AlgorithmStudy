#include <iostream>
using namespace std;

int main(){
	int n, d;
	cin >> n >> d;
	int ans1 = n / d * d, ans2 = ans1 + d;
	if (n - ans1 < ans2 - n) cout << ans1 << endl;
	else if (ans2 - n < n - ans1) cout << ans2 << endl;
	else cout << ans1 << endl << ans2 << endl;
	return 0;
}