#include<bits/stdc++.h>

using namespace std;

#define int long long
int n, h[5003];

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int len = 1; len <= n; len++) {
		int minn = 0x3f3f3f3f3f3f3f3f;
		for (int i = 1; i <= n; i++) {
			int j = i + len - 1;
			if (j > n) break; 
			int minx = 0;
			for (int k = i; k <= j; k++) {
				minx += abs(h[k] - h[j]), j--;
			}
			minn = min(minn, minx);
		}
		cout << minn << " ";
	}
	return 0;
}
