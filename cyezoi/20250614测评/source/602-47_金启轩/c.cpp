#include <bits/stdc++.h>
using namespace std;
int n, h[5005], sans[5005][5005], ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> h[i];
	cout << 0 << " ";
	for (int i = 2; i <= n; ++i) {
		ans = 0x3f3f3f3f;
		for (int j = 1; j <= n - i + 1; ++j) {
			sans[j][i] = sans[j + 1][i - 2] + abs(h[j] - h[j + i  - 1]);
			ans = min(ans, sans[j][i]);
		}
		cout << ans << " ";
	}
	return 0;
}

