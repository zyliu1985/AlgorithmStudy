#include <bits/stdc++.h>
using namespace std;

int c, cnt;
bool n;
bitset<400005> w[4];

int main() {
	cin >> c;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < c; j++) {
			cin >> n;
			if (n) {
				if (i == 0) {
					w[0][j].flip();
					w[1][j].flip();
					w[1][j + 1].flip();
				} else if (i == 1) {
					w[(j % 2 ? 3 : 0)][j].flip();
					w[2][j].flip();
					w[2][j + 1].flip();
				}
			}
		}
	}
	for (int i = 0; i <= 3; i++) {
		cnt += w[i].count();
	}
	cout << cnt;
}
