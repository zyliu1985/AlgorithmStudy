#include<bits/stdc++.h>

using namespace std;

int n, m, a[3005], b[105], f[105][4][3005];
int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i=1; i<=m; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i=0; i<=m; ++i) {
		f[i][0][0] = 0;
		f[i][1][0] = 0;
		for (int j=1; j<=n; ++j) {
			f[i][0][j] = max(f[i][1][j - 1], max(f[i][0][j - 1], max(f[i][2][j - 1], f[i][3][j - 1])));
			f[i][1][j] = max(f[i][0][j - 1], f[i][2][j - 1]) + a[j];
			if (i) {
				f[i][0][j] = max(f[i][0][j], f[i - 1][0][j]);
			    f[i][1][j] = max(f[i][1][j], f[i - 1][1][j]);
				f[i][2][j] = max(f[i - 1][1][j], f[i - 1][3][j]);
				f[i][3][j] = max(f[i - 1][0][j], f[i - 1][2][j]) + b[i];
			}
		}
	}
	cout << max(f[m][0][n], max(f[m][1][n], max(f[m][2][n], f[m][3][n])));
	return 0;
}
