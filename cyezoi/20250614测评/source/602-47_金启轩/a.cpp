#include <bits/stdc++.h>
using namespace std;
int n;
struct STR {int sum, id;} num[10];
string s;
bool cmp(STR a, STR b) {
	if (a.sum == b.sum) return a.id < b.id;
	else return a.sum > b.sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 5; ++i) num[i].id = i;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		for (int j = 0; j < 5; ++j)
			if (s[j] == 'Y') num[j + 1].sum++;
	}
	sort (num + 1, num + 6, cmp);
	int maxx = num[1].sum;
	cout << num[1].id;
	for (int i = 2; i <= 5; ++i)
		if (num[i].sum == maxx) cout << "," << num[i].id;
	return 0;
}

