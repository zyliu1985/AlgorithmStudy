#include <bits/stdc++.h>

using namespace std;

int n, cnt[10], maxn = 0;
bool flag = true;
char tmp;
int main() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<5; ++j) {
			cin >> tmp;
			if (tmp == 'Y') {
				cnt[j] ++;
				maxn = max(maxn, cnt[j]);
			}
		}
	}
	for (int i=0; i<5; ++i) {
		if (cnt[i] == maxn) {
			if (!flag) cout << ",";
			cout << i + 1;
			flag = false;
		}
	}
	cout << endl;
	return 0;
}
