#include <iostream>
#include <algorithm>
using namespace std;

int a[11] = {0,7,9,11,13,14,12,10,8,6,4};

int main(){
	int m = 5;
	int minc = 1e9, minn = 1e9;
	for (int i = 1; i <= 10; i++){
		if (abs(a[i]-m) <= minc){
			minn = min(minn, a[i]);
		}
	}
	cout << minn << endl;
	return 0;
}