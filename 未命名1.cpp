#include <iostream>
#include <math.h>
using namespace std;

string compute(long long n) {
	int x = 1;
	long long sum = pow(2, x);
	while(n > sum) {
		x++;
		sum += (long long) pow(2, x);
	}
	
//	cout << "pos: " << x << endl;
	sum /= 2;
//	cout << "sum = " << sum << endl;
	string rv = "";
	while (x >= 1) {
		x--;
		long long diff = n - sum;
//		cout << "diff=" << diff << ", power=" << pow(2, x) <<", sum=" << sum << ", n=" << n << ", rv=";
		if(diff >= pow(2, x)) {
			rv += "8";
//			cout << rv << endl;
			sum += (long long) pow(2, x);
		} else {
			rv += "6";
//			cout << rv << endl;
		}
	}

	return rv;
}

int main(){
	long long n;
	cin >> n;
	
//	cout << "n=" << n << endl;
	
	cout << compute(n) << endl;
	return 0;
}