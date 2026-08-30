//Koenegsegg Agera R (Dino's)
//Ô¤¼ÆµÃ·Ö:120-240
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[3005], b[105], f[10000][2], tt[10000];
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	if (m == 0) {
		f[1][1] = a[1];
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				f[i][0] = max(f[i][0], max(f[j][1], f[j][0]));
			}
			for (int j = 1; j < i - 1; j++) {
				f[i][1] = max(f[i][1], max(f[j][1], f[j][0]));
			}
			f[i][1] = max(f[i][1], f[i - 1][0]);
			f[i][1] += a[i];
		}
		cout << max(f[n][1], f[n][0]) << endl;
	}
	else if (m == 1) {
		int ans = 0;
		for (int k = 0; k <= n; k++) {
			memset(tt, 0, sizeof(tt));
			memset(f, 0, sizeof(f));
			for (int i = 1; i <= k; i++) tt[i] = a[i];
			tt[k + 1] = b[1];
			for (int i = k + 1; i <= n; i++) tt[i + 1] = a[i];
			f[1][1] = tt[1];
			for (int i = 2; i <= n + 1; i++) {
				for (int j = 1; j < i; j++) {
					f[i][0] = max(f[i][0], max(f[j][1], f[j][0]));
				}
				for (int j = 1; j < i - 1; j++) {
					f[i][1] = max(f[i][1], max(f[j][1], f[j][0]));
				}
				f[i][1] = max(f[i][1], f[i - 1][0]);
				f[i][1] += tt[i];
			}
			ans = max(ans, max(f[n + 1][1], f[n + 1][0]));
		}
		cout << ans;
	} 
	else {
		cout << 44;
	}
	return 0;
} 
