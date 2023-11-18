#include<iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	if(2 * n < k) {
		cout << 2 << endl;
	} elseif(2 * n % k == 0) {
		cout << 2 * n / k << endl;
	} else {
		cout << 2 * n / k + 1 << endl;
	}
	
	return 0;
}