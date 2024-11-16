#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, a[100005];
long long sumA = 0, sumB = 0;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a+1, a+n+1);
	
	bool flag = true; 
	long long sumAS = 0, sumBS = 0, sumAD = 0, sumBD = 0;
	 for(int i = 1; i <= n; i++) {
	 	if(flag) {
	 		sumAS += a[i];
	 		sumAD += a[n - i + 1];
	 		flag = false;
		 } else {
		 	sumBS += a[i];
		 	sumBD += a[n - i + 1];
		 	flag = true;
		 }
	 }
	
	cout << max(abs(sumAS) - abs(sumBS), abs(sumAD) - abs(sumBD)) << endl;
	
	return 0;
}
