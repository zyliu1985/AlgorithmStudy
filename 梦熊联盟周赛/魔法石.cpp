#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int main(){
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	long long x,y,z;
	cin >> x >> y >> z;
	
	if(x != y && y != z && x != z) cout << "NO" << endl;
	else {
		long long maxV = max(max(x, y), max(y, z));
		long long minV = min(min(x, y), min(y, z));
		if(maxV == x) {
			if(maxV == y || maxV == z) {
				cout << "YES" << endl;
				cout << minV << ' ' << minV << ' ' << maxV << endl;
			} else {
				cout << "NO" << endl;
			} 
		} else if(maxV == y) {
			if(maxV == z) {
				cout << "YES" << endl;
				cout << minV << ' ' << minV << ' ' << maxV << endl;
			} else {
				cout << "NO" << endl;
			} 
		} else {
			cout << "NO" << endl;
		}
	} 
	 
	return 0;
}
