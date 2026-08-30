//Skyline GT-R (R34) (Paul Walker's)
//Ô¤¼ÆµÃ·Ö:400 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int g;
int n, ans;
int a[100010];
int l[100010];
signed main() {
//	freopen("data.in", "r", stdin);
	cin >> g;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	for (int i = 1; i <= g; i++) {
		l[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int t = a[i];
		while (t != l[t]) {
			l[t] = l[l[l[l[l[t]]]]];
			t = l[t];
		}
		if (t == 0) break;
		l[t] = t - 1;
		l[a[i]] = t - 1;
		ans++;
	}
	cout << ans;
	return 0;
}
