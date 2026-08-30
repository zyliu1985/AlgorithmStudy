//Polestar 2 [NFS Edition]
//Ô¤¼ÆµÃ·Ö:200
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans;
int a[200005], b[200005];
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			ans += 3;
			if (a[i - 1] == 1) ans -= 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] == 1) {
			ans += 3;
			if (b[i - 1] == 1) ans -= 2;
			if (i % 2 == 1 && a[i] == 1) ans -= 2;
		}
	}
	cout << ans;
	return 0;
}
