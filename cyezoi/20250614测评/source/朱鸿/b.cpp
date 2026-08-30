#include <bits/stdc++.h>
using namespace std;

const int maxc = 200005;

int c;
bool a[2][maxc];
bool vis[2][maxc];
int ans;

void solve(int x, int y) {
	vis[x][y] = 1;
	ans++;
	if (x != 1 && a[x + 1][y] == 1) solve(x + 1, y);
	if (y != c - 1 && a[x][y + 1] == 1) solve(x, y + 1);
}

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 1 && vis[i][j] == 0) {
				ans += 2;
				solve(i, j);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
