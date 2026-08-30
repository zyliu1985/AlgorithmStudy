#include<bits/stdc++.h>

using namespace std;

#define int long long
int n, m;
int a[3100], f[3100][2], t[3100];

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	if (m == 0) {
		for (int i = 1; i <= n; i++) {
			f[i][1] = f[i-1][0] + a[i];
			f[i][0] = max(f[i-1][0], f[i-1][1]);
		}
		cout << max(f[n][0], f[n][1]) << "\n";
	}
	else if (m == 1) {
		int b; cin >> b;
		int maxn = 0;
		for (int i = 1; i <= n + 1; i++) {
			memset(t, 0, sizeof t);
			memset(f, 0, sizeof f);
			int k = 1;
			for (int j = 1; j <= n + 1; j++) {
				if (j == i) t[j] = b;
				else t[j] = a[k++];
			}
			for (int j = 1; j <= n + 1; j++) {
				f[j][1] = f[j-1][0] + t[j];
				f[j][0] = max(f[j-1][0], f[j-1][1]);
			}
			maxn = max(maxn, max(f[n + 1][0], f[n + 1][1]));
		}
		cout << maxn;
	}
	return 0;
}
