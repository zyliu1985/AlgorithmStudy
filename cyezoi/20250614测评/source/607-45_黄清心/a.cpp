//BMW M3 E46 GTR [NFS Edition]
//Ô¤¼ÆµÃ·Ö:100 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s[100005];
int a[10];
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (int j = 0; j < 5; j++) {
			if (s[i][j] == 'Y') a[j + 1]++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 5; i++) {
		ans = max(ans, a[i]);
	}
	bool f = 0;
	for (int i = 1; i <= 5; i++) {
		if (a[i] == ans) {
			if (f) cout << ",";
			cout << i;
			f = 1;
		}
	}
	cout << endl;
	return 0;
}
