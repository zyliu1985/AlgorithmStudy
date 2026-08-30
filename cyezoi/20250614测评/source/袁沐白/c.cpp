#include <bits/stdc++.h>
using namespace std;
int n, a[5010];
long long c[5010];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		c[i] = c[i - 1] + a[i];
	}
	for(int len = 1; len <= n; len ++) {
		int l = 1, r = l + len - 1;
		int ans = 214748354;
		while(r <= n) {
			int mid = (l + r) / 2;
			int x = c[mid] - c[l - 1];
			int y = c[r] - c[mid - 1];
			ans = min(ans, abs(x - y));
			l ++, r ++;
		}
		cout << ans << " ";
	}
	return 0;
}
