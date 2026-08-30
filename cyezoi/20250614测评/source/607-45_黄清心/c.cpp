//Nissan 350Z (Rachel's)
//Ô¤¼ÆµÃ·Ö:300
#include <bits/stdc++.h>
using namespace std;
int n;
int h[5005];
int a[5005], b[5005], ans1 = 0x7fffffff, ans2 = 0x7fffffff;
signed main() {
//	freopen("data.in", "r", stdin);
//	freopen("data2.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		if (i > 1) b[i - 1] = abs(h[i] - h[i - 1]);
		if (i > 1) ans2 = min(ans2, b[i - 1]);
	}
	cout << 0 << " " << ans2 << " ";
//	cout << endl;
	for (int i = 3; i <= n; i++) {
		int temp = 0x7fffffff;
		for (int j = 2; j + i - 2 <= n; j++) {
			if (i % 2 == 1){
				a[j - 1] = a[j] + abs(h[j - 1] - h[j + i - 2]);
				temp = min(temp, a[j - 1]);	
			}
			if (i % 2 == 0){
				b[j - 1] = b[j] + abs(h[j - 1] - h[j + i - 2]);
				temp = min(temp, b[j - 1]);	
			}
		}
//		for (int j = 1; j <= n; j++) {
//			if (i % 2 == 1) cout << a[j] << " ";
//			else cout << b[j] << " ";
//		}
//		cout << endl;
		cout << temp << " ";
//		cout << endl;
	}
	
	return 0;
}
