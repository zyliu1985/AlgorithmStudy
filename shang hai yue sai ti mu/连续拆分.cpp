#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	bool isNone = true;
	cin >> n;
	for (int i = 1; i <= n/2; i++){
		int dir = 1+4*(n*2 + i*i - i);
		int j = (sqrt(dir) - 1) / 2;
		
//		for (int j = 1; j <= n; j++){ // n*2
//		// j(i+j) - i(i+j) + i+j <= n*2
//		// j*j - i*i + i + j <= n*2
//		// j*j+j <= n*2 + i*i - i
//		// j*j + j - (n*2 + i*i - i) <= 0
//		// dir = 1+4*(n*2 + i*i - i)
//		// j < (-1 + sqrt(dir)) / 2
//		// 
//			if ((i + j) * (j - i + 1) / 2 == n){
//				for (int k = i; k <= j; k++) cout << k << ' ';
//				cout << endl;
//				isNone = false;
//			} else if ((i + j) * (j - i + 1) / 2 > n) break;
//		}
		if ((i + j) * (j - i + 1) / 2 == n){
			for (int k = i; k <= j; k++) cout << k << ' ';
			cout << endl;
			isNone = false;
		}
	}
	if (isNone) cout << "None" << endl;
	return 0;
}