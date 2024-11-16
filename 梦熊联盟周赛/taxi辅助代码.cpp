#include <iostream>
using namespace std;

int main(){
	freopen("taxi10.in", "w", stdout);
	cout << 1e5 << ' ' << 1e5 << endl;
	for (int i = 1; i <= 2e5; i++)
		cout << i << ' ';
	cout << endl;
	for (int i = 1; i <= 1e5; i++)
		cout << 0 << ' ' << 1 << ' ';
	return 0;
}
