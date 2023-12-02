#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int x = 1;
	while (x <= n){
		n -= x;
		x++;
	}
	cout << x-1 << endl;
	return 0;
}