#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
int b[200010];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++) {
		cin >> b[i];
	}
	int ch = 0, ans = 0;
	for(int i = 1; i < n; i ++) {
		if(a[i] == a[i + 1] && a[i] == 1) ch ++;
		if(b[i] == b[i + 1] && b[i] == 1) ch ++;
		if(a[i] == b[i] && i % 2 == 1 && a[i] == 1) ch ++;
		if(a[i] == 1) ans ++;
		if(b[i] == 1) ans ++;
	}
	if(a[n] == b[n] && n % 2 == 1 && a[n] == 1) ch ++;
	if(a[n] == 1) ans ++;
	if(b[n] == 1) ans ++;
	cout << ans * 3 - ch * 2 << endl;
	return 0;
}
