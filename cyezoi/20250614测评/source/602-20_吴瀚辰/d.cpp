#include <bits/stdc++.h>
using namespace std;

int p, q, g, cnt;
bool flag;
bitset<100000> a;

int main() {
	cin >> g >> p;
	for (int i = 0; i < p; i++) {
		cin >> q;
		for (int i = q; i > 0; i--) {
			flag = 0;
			if (a[i] == 0) {
				a[i] = 1;
				flag = 1;
				break;
			}
		}
		if (!flag) break;
		else cnt++;
	}
	cout << cnt;
}
