#include <iostream>
#include <cmath>
using namespace std;

void digui(int n) {
	for(int j = n; j >= 1; j--) {
		cout << '(';
	}
	
	for(int j = n; j >= 1; j--) {
		cout << ')';
	}
	
	digui(n-1);
}

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < min(1000, n); i++) {
		for(int j = n - i; j >= 1; j--) {
			cout << '(';
		}
		
		for(int k = 0; k < i; k++) {
			cout << ')'
		}
		
		for(int j = n; j >= 1; j--) {
			cout << ')';
		}
		
		cout << endl;
	}
}