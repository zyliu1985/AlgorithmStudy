#include <bits/stdc++.h>

using namespace std;

int c;
bool a[5][200005];
long long ans = 0;
int main() {
	cin >> c;
	for (int i=1; i<=2; ++i) {
		for (int j=1; j<=c; ++j) {
			cin >> a[i][j];
			if (a[i][j]) ans += 3;
		}
	}
	for (int i=1; i<=2; ++i) {
		for (int j=1; j<=c; ++j) {
			if (a[i][j]) ans -= a[i][j - 1] + a[i][j + 1];
			if (j % 2 == 1 && a[i][j]) {
				if (i == 1 && a[2][j]) ans --;
				if (i == 2 && a[1][j]) ans --;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
