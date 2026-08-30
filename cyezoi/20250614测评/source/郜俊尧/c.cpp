#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;
typedef long long ll;
int a[5005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int k = 1; k <= n; k++) {
		ll cur = INT_MAX;
		for (int p = 0; p <= n - k; p++) {
			ll tmp = 0;
			for (int i = 1 + p, j = k + p; i <= j;) {
				tmp += abs(a[i] - a[j]);
				i++, j--;
			}
			cur = min(tmp, cur);
		}
		cout << cur << " ";
	}

	return 0;
}

