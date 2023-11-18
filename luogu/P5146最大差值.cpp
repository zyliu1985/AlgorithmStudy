#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n, a[1000005], s[1000005], ans = -1e18;
signed main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	int minn = 1e18;
	for (int i = 1; i <= n; i++){
		ans = max(ans, a[i]-minn);
		minn = min(minn, a[i]);
	}
	cout << ans << endl;
	return 0;
}