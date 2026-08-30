#include <bits/stdc++.h>
using namespace std;

int n, cnt, mx;
char c;
bool flag;
bool date[8];
bitset<100005> a[5];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> c;
			a[j][i] = (c == 'Y');
		}
	}
	for (int i = 0; i < 5; i++) {
		cnt = a[i].count();
		if (cnt > mx) {
			mx = cnt;
			memset(date, 0, sizeof(date));
		}
		if (cnt == mx) {
			// 人数超过最多或和最多持平，都要设置为true
			// 所以如果人数超过最多，在第21行设置mx，所以也会进入27行 
			date[i + 1] = true;
		}
	}
	for (int i = 1; i <= 5; i++) {
		if (date[i] == true) {
			cout << (flag ? "," : "") << i;
			flag = true;
		}
	}
}
