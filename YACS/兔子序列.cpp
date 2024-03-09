#include<iostream>
using namespace std;

int a, k;

int f(int n) {
	if(n == 1) return 1;
	if(n == 2) return a;
	return f(n-1) + f(n-2);
}

int main() {
	cin >> a >> k;
	
	int cnt = 0;
	
	for(int i = 1; i <= k; i++) {
		int fi = f(i);
//		cout << "f[" << i << "]=" << fi <<endl;
		if(fi > k) {
			cout << i - 1 ;
			return 0;
		}
	}
	return 0;
}