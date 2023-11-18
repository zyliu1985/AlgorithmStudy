#include <iostream>
#define int long long
using namespace std;

signed main(){
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		sum += i*(n/i);
	}
	cout << sum << endl;
	return 0;
}