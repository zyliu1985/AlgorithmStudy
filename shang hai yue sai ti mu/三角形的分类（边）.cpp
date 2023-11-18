#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if(a + b > c && a + c > b && b + c > a) {
		if (a == b && b == c){
			cout << "Equilateral" << endl;
			return 0;
		}
		if (a >= b && a >= c){
			if (pow(b, 2) + pow(c, 2) == pow(a, 2)){
				if (b == c) {
					cout << "Isosceles right" << endl;
					return 0;
				}
				else {
					cout << "Right" << endl;
					return 0;
				}
			} else {
				if (b == c){
					cout << "Isosceles" << endl;
					return 0;
				}
			}
		} else if (b >= a && b >= c){
			if (pow(a, 2) + pow(c, 2) == pow(b, 2)){
				if (a == c) {
					cout << "Isosceles right" << endl;
					return 0;
				}
				else {
					cout << "Right" << endl;
					return 0;
				}
			} else {
				if (a == c){
					cout << "Isosceles" << endl;
					return 0;
				}
			}
		} else {
			if (pow(a, 2) + pow(b, 2) == pow(c, 2)){
				if (a == b) {
					cout << "Isosceles right" << endl;
					return 0;
				}
				else {
					cout << "Right" << endl;
					return 0;
				}
			} else {
				if (a == b){
					cout << "Isosceles" << endl;
					return 0;
				}
			}
		}
		cout << "Scalene" << endl;
		return 0;
	} else {
		cout << "Error" << endl;
		return 0;
	}
	return 0;
}