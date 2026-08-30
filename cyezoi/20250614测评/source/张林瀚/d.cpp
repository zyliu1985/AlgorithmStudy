#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

int n, a[N], s[N];
int f[N], ans;

int main() {
	cin >> n;
	int p;
	cin >> p;
	for (int i = 1; i <= p; i++) {
		cin >> a[i];
		f[a[i]]++;
	}
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		if (f[i] > 0) ans++, f[i]--;
		else {
			vec.push_back(i);
		}
	}
	for (int i = n; i >= 1; i--) s[i] = s[i - 1] + f[i];
	int m = 0;
	for (int i : vec) {
		s[i] -= m;
		if (s[i] > 0) {ans++, m++;}
	}
	cout << ans << "\n";
	return 0;
}
