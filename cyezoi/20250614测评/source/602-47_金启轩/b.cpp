#include <bits/stdc++.h>
using namespace std;
int c, a[5][200005], now, ans;
bool vis[5][200005], f;
int dfs(int x, int y) {
	int sans = 0;
	vis[x][y] = 1;
	if (x == 1) {
		if (y < c && a[x][y + 1] == 1 && !vis[x][y + 1]) sans += dfs(x, y + 1);
		if (a[x + 1][y] == 1 && !vis[x + 1][y]) sans += dfs(x + 1, y);
		return sans + 1;
	}
	else {
		if (y < c && a[x][y + 1] == 1 && !vis[x][y + 1]) sans += dfs(x, y + 1);
		return sans + 1;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c;
	for (int i = 1; i <= c; ++i) cin >> a[1][i];
	for (int i = 1; i <= c; ++i) cin >> a[2][i];
	if (c % 2 == 0) f = 1, c--;
	for (int i = 1; i <= c; ++i) {
		if (a[1][i] && !vis[1][i]) now += dfs(1, i);
		else  {
			if (now == 0) continue;
			else ans += now + 2, now = 0;
		}
	}
	if (now) ans += now + 2, now = 0;
	for (int i = 1; i <= c; ++i) {
		if (a[2][i] && !vis[2][i]) now += dfs(2, i);
		else  {
			if (now == 0) continue;
			else ans += now + 2, now = 0;
		}
	}
	if (now) ans += now + 2, now = 0;
	if (f) {
		if (a[1][c + 1]) {
			if (a[1][c]) ans++;
			else ans += 3;
		}
		if (a[2][c + 1]) {
			if (a[2][c]) ans++;
			else ans += 3;
		}
	}
	cout << ans << endl;
	return 0;
}

