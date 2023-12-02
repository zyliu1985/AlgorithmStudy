#include <iostream>
#include <algorithm>
using namespace std;

int a[4] = {0, 3, 3, 5};
int main(){
	cout << lower_bound(a+1, a, 2) - a << endl;
	return 0;
}