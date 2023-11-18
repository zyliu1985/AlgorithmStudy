#include <iostream>
using namespace std;

int main() {
	int n, a;
	cin >> n >> a;
	
	int ans = a;
	for(int i = n - 1; i>=0; i--) {
		ans = (ans - 1) * 2;
	}
	
	cout << ans;
	return 0;
}