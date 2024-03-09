#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	cout << (n/2+n%2)*m + n/2*(m/2) << endl;
//	cout << n/2*m/2*3 << endl;
	return 0;
}