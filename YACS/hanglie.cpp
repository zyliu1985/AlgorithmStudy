#include <iostream>
using namespace std;

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	
	if(c % m == 0) {
		cout << c / m << ' ' << m << endl;
	} else {
		cout << c / m + 1 << ' ' << c % m << endl;
	}
	
	return 0;
}