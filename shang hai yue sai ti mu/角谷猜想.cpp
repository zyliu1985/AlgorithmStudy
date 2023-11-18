#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	while (n > 1){
		if (n & 1) n = n*3+1;
		else n /= 2;
		cout << n << ' ';
	}
	return 0;
}