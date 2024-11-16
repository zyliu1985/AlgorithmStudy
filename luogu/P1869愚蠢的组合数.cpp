#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		if (k == 0 || k == n) cout << 1 << endl;
		else cout << (n & 1) << endl;
	}
	return 0;
}