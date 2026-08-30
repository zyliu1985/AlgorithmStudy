#include <iostream>
#include <algorithm>
using namespace std;

int a[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	long long ans = 0;
	cin >> n;
	int lst = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] == 1){
			ans++;
			int l = lst, r = i-1;
			while (l < r){
				if (a[l] >= a[r]){
					ans += a[l] * a[l+1];
					l++;
				} else {
					ans += a[r] * a[r-1];
					r--;
				}
			}
			if (l == r) ans += a[l];
			lst = i+1;
		}
	}
	int l = lst, r = n;
	while (l < r){
		if (a[l] >= a[r]){
			ans += a[l] * a[l+1];
			l++;
		} else {
			ans += a[r] * a[r-1];
			r--;
		}
	}
	if (l == r) ans += a[l];
	cout << ans << '\n';
	return 0;
}

