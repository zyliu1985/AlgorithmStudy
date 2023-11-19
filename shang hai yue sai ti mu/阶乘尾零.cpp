#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	int sum5 = 0, i;
	for (i = 1; pow(5, i) <= n; i++){
		sum5 += n/pow(5, i);
	}
	cout << sum5 << endl;
	return 0;
}