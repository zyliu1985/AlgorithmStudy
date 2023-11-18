#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if (a >= b && a >= c){
		if (pow(b, 2) + pow(c, 2) == pow(a, 2)){
			cout << "Right Triangle" << endl;
		} else {
			cout << "No" << endl;
		}
	} else if (b >= a && b >= c){
		if (pow(a, 2) + pow(c, 2) == pow(b, 2)){
			cout << "Right Triangle" << endl;
		} else {
			cout << "No" << endl;
		}
	} else {
		if (pow(a, 2) + pow(b, 2) == pow(c, 2)){
			cout << "Right Triangle" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}