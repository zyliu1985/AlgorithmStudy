#include <bits/stdc++.h>
using namespace std;
int g, p, ls[100010];
bool used[100010];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> g >> p;
	int maxn = -1e9;
	for (int i = 1; i <= p; i ++)
		cin >> ls[i], maxn = max(maxn, ls[i]);
	g = min(g, maxn);
	if (p <= 20000 && g <= 20000) {
		for (int i = 1; i <= p; i ++) {
			bool flag = 1;
			for (int j = ls[i]; j; j --) {
				if (! used[j]) {
					used[j] = 1, flag = 0;
					break;
				}
			}
			if (flag) {
				cout << i - 1;
				return 0;
			}
		}
		cout << p;
		return 0;
	}
	set<int> s;
	for (int i = 1; i <= p; i ++)
		s.insert(ls[i]);
	cout << (int)s.size();
}
