#include <bits/stdc++.h>
using namespace std;

int n;
char c;
int cnt[6];
int maxcnt;
vector<int> ans;

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> c;
			if (c == 'Y') cnt[j]++;
		}
	}
	for (int i = 1; i <= 5; i++) {
		if (cnt[i] > maxcnt) {
			ans.clear();
			maxcnt = cnt[i];
		}
		if (cnt[i] == maxcnt) {
			ans.push_back(i);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size() - 1) cout << ",";
	}
	cout << "\n";
	return 0;
}
