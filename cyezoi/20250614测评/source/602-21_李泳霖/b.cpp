#include<bits/stdc++.h>

using namespace std;

#define int long long
int n, ans;
int a[3][200005];

signed main() {
	cin >> n;
	for (int i = 1; i <= 2; i++) 
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 1) {
				ans += 3;
				if (a[i][j-1] == 1) ans++, a[i][j-1] = 3;
				else if (a[i][j+1] == 1) ans++, a[i][j+1] = 3;
				if (j & 1) {
					if (i == 1 && a[i+1][j] == 1) ans++, a[i+1][j] = 3;
					else if (i == 2 && a[i-1][j] == 1) ans++, a[i-1][j] = 3;
				}
				a[i][j] = 3;
			}
		}
	}
	cout << ans;
	return 0;
}
