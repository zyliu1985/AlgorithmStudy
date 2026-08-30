#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> cnt[6];
bool cmp (pair<int, int> lhs, pair<int, int> rhs) {return lhs.first > rhs.first;}
int main() {
	for (int i = 1; i <= 5; ++i) cnt[i].second = i;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 5; ++j) {
			char c;
			cin >> c;
			if (c == 'Y') ++cnt[j].first;
		}
	sort(cnt + 1, cnt + 6, cmp);
	for (int i = 1; i <= 5; ++i)
		if (cnt[i].first > cnt[i + 1].first) {
			cout << cnt[1].second;
			for (int j = 2; j <= i; ++j) cout << "," << cnt[j].second;
			break;
		}
	return 0;
}
