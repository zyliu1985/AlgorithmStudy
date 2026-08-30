#include <bits/stdc++.h>
using namespace std;
int n, k, l = 0;
int plane[100010];
int main() {
	cin >> n >> k;
	for(int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		if(l > 0) continue;
		bool flag = 0;
		for(int j = x; j >= 1; j --) {
			if(plane[j] == 0) {
				plane[j] = 1;
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			l = i - 1;
		}
	}
	if(l > 0) cout << l << endl;
	if(l == 0) {
		cout << k << endl;
	}
	return 0;
}
