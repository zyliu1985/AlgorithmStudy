#include <iostream>
#define int long long
using namespace std;

string s[1005];
signed main(){
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int _ = 1; _ <= q; _++){
		int a, b, c, d, ans = 0;
		cin >> a >> b >> c >> d;
		for (int i = a; i <= c; i++){
			for (int j = b; j <= d; j++){
				if (s[i%n][j%n] == 'B') ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}