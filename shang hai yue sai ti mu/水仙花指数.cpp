#include <iostream>
#include <map>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int ans = 0;
	while (n > 0) {
		int m = n % 10;
		n = n / 10;
		ans += m * m * m;
	}
	
	cout << ans << endl;
	return 0;
}