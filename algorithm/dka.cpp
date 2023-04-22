#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string tt, ss;
map<string, map<string, int>> mp;
map<string, int> wsum;
map<string, string> ftr;
map<string, bool> out;

bool over() {
	for (auto kv : out) {
		if (!kv.second) {
			return false;
		}
	}
	return true;
}

void dka() {
	string cnts;
	int cnti = 1e6;
	for (auto kv : wsum) {
		if (kv.second < cnti && !out[kv.first]) {
			cnti = kv.second;
			cnts = kv.first;
		}
	}
	if (over()) {
		wsum[ss] = -1;
		return;
	}
	if (cnts == ss) {
		return;
	}
	for (auto kv : mp[cnts]) {
		if ((!wsum.count(kv.first)) || cnti+kv.second < wsum[kv.first]) {
			wsum[kv.first] = cnti+kv.second;
			ftr[kv.first] = cnts;
		}
	}
	out[cnts] = true;
	dka();
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		map<string, int> mp2;
		int m;
		cin >> m;
		for (int j = 1; j <= m; j++) {
			string t;
			int x;
			cin >> t >> x;
			mp2[t] = x;
		}
		mp[s] = mp2;
	}
	cin >> tt >> ss;
	if (!mp.count(tt)) {
		cout << -1 << endl;
		return 0;
	}
	if (ss == tt) {
		cout << 0 << endl << tt;
		return 0;
	}
	wsum[tt] = 0;
	dka();
	cout << wsum[ss] << endl;
	if (wsum[ss] == -1) {
		return 0;
	}
	string bf[105];
	string s = ss;
	int j = 1;
	while (s != tt) {
		bf[j] = s;
		s = ftr[s];
		j++;
	}
	cout << tt;
	j--;
	for (int i = j; i >= 1; i--) {
		cout << "->" << bf[i];
	}
	return 0;
}