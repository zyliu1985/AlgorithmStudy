#include <iostream>
#include <algorithm>
using namespace std;

int a[200005], b[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += min(a[i], b[i]);
	while (q--){
		char c;
		int x, y;
		cin >> c >> x >> y;
		ans -= min(a[x], b[x]);
		if (c == 'A'){
			a[x] = y;
		} else {
			b[x] = y;
		}
		ans += min(a[x], b[x]);
		cout << ans << '\n';
	}
	return 0;
}

