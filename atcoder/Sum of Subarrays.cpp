#include <iostream>
#include <algorithm>
using namespace std;

int a[300005];
long long s[300005], ss[300005], ss1[300005], ss2[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
		ss[i] = ss[i-1] + s[i];
		ss1[i] = ss1[i-1] + s[i] * i; 
	}
	for (int i = n; i >= 1; i--)
		ss2[i] = ss2[i+1] + s[i] * (n - i + 1);
//	for (int i = 1; i <= n; i++){
//		cout << s[i] << ' ' << ss[i] << ' ' << ss1[i] << ' ' << ss2[i] << '\n';
//	}
	ss2[0] = ss2[1];
	while (q--){
		long long l, r;
		cin >> l >> r;
		cout << ss1[r] - ss1[l-1] - (l-1) * (ss[r] - ss[l-1]) - (ss2[l-1] - ss2[r] - (n-r+1) * (ss[r-1] - ss[max(0 * 1ll, l-2)])) << '\n';
	}
	return 0;
}

