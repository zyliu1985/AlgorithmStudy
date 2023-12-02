#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	if (abs(n) % 2 == 0) cout << "even" << endl;
	else cout << "odd" << endl;
	return 0;
}