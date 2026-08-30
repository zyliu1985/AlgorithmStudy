#include <bits/stdc++.h>
using namespace std;
int g, p, a[100005], now;
bool b[100005], f;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> g >> p;
	for (int i = 1; i <= p; ++i) cin >> a[i];
	for (int i = 1; i <= p; ++i) {
		f = 1;
		for (int j = a[i]; j > now; --j) {
			if (!b[j]) {
				b[j] = 1, f = 0;
				break;
			}
		}
		while (b[now + 1]) ++now;
		if (f) {
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << p << endl;
	return 0;
}

