#include <iostream>
#include <algorithm>
using namespace std;

int a[200005], t[200005], at[200005];
int main(){
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i <= n; i++) at[i] = a[i]-t[i];
	sort(at+1, at+n+1);
//	for (int i = 1; i <= n; i++) cout << at[i] << ' ';
//	cout << endl;
	for (int i = 1; i <= q; i++){
		int v, s;
		cin >> v >> s;
		int cur = upper_bound(at+1, at+n+1, s) - at;
		if (n - cur + 1 >= v) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}