#include <iostream>
#include <map>

using namespace std;
const int N = 1e5 + 10;

map<int, int> mp;
int ans[N], cur;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'Y')
				mp[j + 1]++;
		}
	}
	int maxx = 0;
	for (auto i : mp)
		maxx = max(maxx, i.second);
	for (auto i : mp) {
		if (i.second == maxx)
			ans[++cur] = i.first;
	}
	for (int i = 1; i <= cur; i++) {
		cout << ans[i];
		if (i < cur) cout << ",";
		else cout << "\n";
	}
	return 0;
}
