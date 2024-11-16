#include <iostream>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	
	int x = b/a + 1;
	while(true) {
		if((x * a) % b == 1) break;
		x++;
	}
	
	cout << x << endl;
	return 0;
}