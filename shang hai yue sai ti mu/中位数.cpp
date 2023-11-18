#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int a[300005];
signed main(){
	int n;
	cin >> n;
	for (int i = 1; i <= 3*n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n*3+1);
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += a[n*3-1-i*2];
	}
	cout << sum << endl;
	return 0;
}