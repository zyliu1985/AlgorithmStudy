#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];

int main(){
	int n, x;
	long long ans = 0;
	cin >> n >> x;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){
		int j = upper_bound(a+i, a+n+1, a[i]+x) - a - 1;
		//cout << "===" << j << endl;
		if (j <= i+1 || j > n){
			continue;
		} else {
			ans += (long long)(j-i) * (long long)(j-i-1) / 2;
		}
		//cout << "***" << ans << endl;
	}
	cout << ans << endl;
	return 0;
}