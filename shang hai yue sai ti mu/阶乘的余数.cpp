#include <iostream>
using namespace std;

int main(){
	int n, m;
	long long ans = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		ans *= i;
		ans %= m;
	}
	cout << ans << endl;
	return 0;
}