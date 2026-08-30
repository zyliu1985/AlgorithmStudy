#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

int a[4][200005];
bool vis[4][200005];
int sum;

void f(int i, int j, int x, int y) {
	if (a[i + x][j + y]) {
		sum -= 2, vis[i + x][j + y] = 1;
//		cout << i << " " << j << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, cnt = 0;

	cin >> c;
	for (int j = 1; j <= 2; j++) {
		for (int i = 1; i <= c; i++) {
			cin >> a[j][i];
			if (a[j][i] == 1) cnt++;
		}
	}

	sum = cnt * 3;

	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= c; j++) {
			if (a[i][j] && !vis[i][j]) {
				f(i, j, 1, 0);
				f(i, j, -1, 0);
				f(i, j, 0, 1);
				f(i, j, 0, -1);
			}

		}
	}


	cout << sum;

	return 0;
}

