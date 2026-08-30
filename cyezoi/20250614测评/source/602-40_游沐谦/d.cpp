#include <bits/stdc++.h>
#define int long long
using namespace std;

int m,n;
bool flag[2005];

signed main() {
	cin >> m >> n;
	for(int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		int tmp = 0;
		for(int j = t; j >= 1; j--) {
			if(!flag[j]) {
				flag[j] = 1;
				tmp = 1;
				//cout << i << ' ' << j << endl;
				break;
			}
		}
		if(!tmp) {
			cout << i-1;
			return 0;
		}
	}
	cout << n;
}


