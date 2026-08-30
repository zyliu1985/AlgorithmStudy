#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[5005];
int f[5005][5005];
int ans[5005];

signed main() {
	for(int i = 1; i <= 5005; i++) ans[i] = 9e18;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 300) {
		cout << 0 << ' ';
		for(int i = 2; i <= n; i++) {
			int an = 9e18;
			for(int j = 1; j <= n-i+1; j++) {
				int tmp = 0;
				for(int k = 0; k <= i-1; k++) {
					tmp += abs(a[j+k]-a[i+j-1-k]);
				}
				tmp /= 2;
				an = min(an,tmp);
			}
			cout << an << ' ';
		}
	}
	if(n > 300) {
		for(int i = 1; i <= (n+1)/2; i++) {
			f[n][1] += a[i]-a[n-i+1];
		}
		ans[n] = f[n][1];
		for(int i = n-1; i >= 1; i--) {
			for(int j = 1; j <= n-i; j++) {
				if(i % 2 == 1) {
					f[i][j] = f[i+1][j] - a[(i+2*j-1)/2] + a[i+j];
				}
				else f[i][j] = f[i+1][j] - a[(i+2*j)/2] + a[i+j];
			}
			for(int j = 0; j < (i+1)/2; j++) {
				f[i][n-i+1] += abs(a[n-i+1+j] - a[n-j]);
			}
			for(int j = 1; j <= n-i; j++) {
				ans[i] = min(ans[i],f[i][j]);
			}
		}
		for(int i = 1; i <= n; i++) {
			cout << ans[i] << ' ';
		}
	}
}
