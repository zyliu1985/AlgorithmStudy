#include <bits/stdc++.h>
using namespace std;
int n;
int a[15];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		string s;
		cin >> s;
		for(int j = 0; j < 5; j ++) {
			if(s[j] == 'Y') a[j] ++;
		}
	}
	int maxn = 0;
	for(int i = 0; i < 5; i ++) {
		maxn = max(maxn, a[i]);
	}
	bool first = 0;
	for(int i = 0; i < 5; i ++) {
		if(a[i] == maxn) {
			if(first == 0) {
				cout << i + 1;
				first = 1;
			} else {
				cout << "," << i + 1;
			}
		}
	}
	return 0;
}
