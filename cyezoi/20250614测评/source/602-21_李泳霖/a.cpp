#include<bits/stdc++.h>

using namespace std;

#define int long long
char a[100005][6];
int n;

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) 
			cin >> a[i][j];
	}
	int cnt[6] = {};
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[j][i] == 'Y') cnt[i]++;
		}
	}
	int maxn = 0, p = 1;
	for (int i = 1; i <= 5; i++) {
		maxn = max(cnt[i], maxn);
	}
	bool flag = 0;
	for (int i = 1; i <= 5; i++) {
		if (cnt[i] == maxn) {
			if (!flag) cout << i, flag = 1;
			else cout << "," << i;
		}
	}
	return 0;
}
