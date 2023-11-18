#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if (a+b+c != 180 || a <= 0 || b <= 0 || c <= 0) {
		cout << "Error" << endl;
		return 0;
	}
	if (a == b && b == c){
		cout << "Equilateral" << endl;
		return 0;
	}
	if (a == 90 || b == 90 || c == 90){
		if (a == b || b == c || c == a){
			cout << "Isosceles right" << endl;
			return 0;
		} else {
			cout << "Right" << endl;
			return 0;
		}
	} else {
		if (a == b || b == c || c == a){
			cout << "Isosceles" << endl;
			return 0;
		} else {
			cout << "Scalene" << endl;
			return 0;
		}
	}
	return 0;
}