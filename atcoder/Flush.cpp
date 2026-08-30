#include <iostream>
#include <algorithm>
using namespace std;

int a[300005];
long long s[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i-1] + a[i];
	while (q--){
		int b;
		cin >> b;
		int t = lower_bound(a+1, a+n+1, b) - a - 1;
		if (t == n){
			cout << -1 << '\n';
		} else {
			cout << s[t] + (n - t) * 1ll * (b - 1) + 1 << '\n';
		}
	} 
	return 0;
}

