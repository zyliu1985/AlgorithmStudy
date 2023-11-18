#include <iostream>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	cout << n/m + (n%m > 0) << endl;
	return 0;
}