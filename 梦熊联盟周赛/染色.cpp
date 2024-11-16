#include <iostream>
using namespace std;

int main(){
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	cout << max(r1 - l1 + r2 - l2 - (max(r1, r2) - min(l1, l2)), 0) << endl; 
	return 0; 
}
