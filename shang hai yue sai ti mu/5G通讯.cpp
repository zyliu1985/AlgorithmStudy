#include <iostream>
#include <algorithm>
using namespace std;

int x[100005];

signed main(){
	long long n, d, cnt = 0;
	cin >> n >> d;
	for (long long i = 1; i <= n; i++){
		cin >> x[i];
	}
	sort(x+1, x+n+1);
	for (long long i = 1; i <= n; i++){
		long long y = x[i]+d;
		long long end = upper_bound(x+1, x+n+1, y) - x - 1;
		cnt += end-i;
	}
	cout << cnt << endl;
	return 0;
}