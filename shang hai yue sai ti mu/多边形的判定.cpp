#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, maxn = 0, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		maxn = max(maxn, x);
		sum += x;
	}
	if (maxn < sum-maxn) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0; 
}