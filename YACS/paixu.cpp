#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	if(a <= b ) {
		if(b <= c) cout << a << ' ' << b << ' ' << c;
		else if (a <= c) cout << a << ' ' << c << ' ' << b;
		else if (a >= c) cout << c << ' ' << a << ' ' << b;
	} else {
		// a > b
		if(c >= a) cout << b << ' ' << a << ' ' << c;
		else if (c <= b) cout << c << ' ' << b << ' ' << a;
		else if (c >= b) cout << b << ' ' << c << ' ' << a;
	}
	
	return 0;
}