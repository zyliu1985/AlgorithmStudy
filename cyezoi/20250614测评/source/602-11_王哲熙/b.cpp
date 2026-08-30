#include <iostream>
#include <cstdio>
using namespace std;
using i64 = long long;
const int MAXC = 2e5 + 5;
bool colour[MAXC][3];
i64 cnt;
int main() {
	int c;
	cin >> c;
	for (int i = 1; i <= c; ++i) cin >> colour[i][1];
	for (int i = 1; i <= c; ++i) cin >> colour[i][2];
	for (int i = 1; i <= c; ++i) {
		if (!colour[i][1]) continue;
		if (colour[i - 1][1] == 1) cnt += 1;
		else cnt += 3;
	}
	for (int i = 1; i <= c; ++i) {
		if (!colour[i][2]) continue;
		if (i & 1) {
			++cnt;
			{if (!colour[i - 1][2]) ++cnt;
			else --cnt;}
			{if (!colour[i][1]) ++cnt;
			else --cnt;}
		} else {
			if (colour[i - 1][2] == 1) cnt += 1;
			else cnt += 3;
		}
	}
	cout << cnt << "\n";
	return 0;
}
