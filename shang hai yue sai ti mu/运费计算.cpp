#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	cout << 12 + max(n-1000, 0) / 500 * 5 + (max(n-1000, 0) % 500 > 0) * 5 << endl;
	return 0;
}