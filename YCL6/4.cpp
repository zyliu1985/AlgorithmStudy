#include <iostream>
using namespace std;

int a[11] = {0,2,4,12,56,7,35,17,34,76,90}, b[11];

int main(){
	for (int i = 1; i <= 10; i++){
		if (i > 5) {
			b[i-5] = a[i];
		} else {
			b[i+5] = a[i];
		}
	}
	for (int i = 1; i <= 10; i++){
		cout << b[i] << ' ';
	}
	return 0;
}