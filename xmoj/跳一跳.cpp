#include <iostream>
#include <algorithm>
using namespace std;

int f[25][500005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, q;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> f[0][i];
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = f[i-1][f[i-1][j]];
	cin >> q;
	while (q--){
		int l, r, ans = 0;
		cin >> l >> r;
		if (l == r){
			cout << 0 << '\n';
			continue;
		}
		for (int i = 20; i >= 0; i--)
			if (f[i][l] < r && f[i][l] != 0) ans += 1 << i, l = f[i][l];
		ans++;
		cout << ans << '\n';
	}
	return 0;
}



