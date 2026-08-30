#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
const int inf = 1e9;

int n;
int h[maxn];
int k[maxn][maxn];

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		// 考虑从 i 向两侧扩展
		int l = i, r = i;
		int k0 = 0;
		k[l][r] = k0;
		while (1 <= l && r <= n) {
			l--; r++;
			k0 += abs(h[l] - h[r]);
			k[l][r] = k0;
		}
		// 考虑从 i 和 i + 1 向两侧扩展
		if (i == n) continue; 
		l = i, r = i + 1;
		k0 = abs(h[l] - h[r]);
		k[l][r] = k0;
		while (1 <= l && r <= n) {
			l--; r++;
			k0 += abs(h[l] - h[r]);
			k[l][r] = k0;
		}
	}
	for (int len = 1; len <= n; len++) {
		int ans = inf;
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			ans = min(ans, k[i][j]);
		}
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}
