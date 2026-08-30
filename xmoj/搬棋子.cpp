#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];
int l[100005], r[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	int ans = 1e9, temp;
	for (int i = 1; i <= n; i++){
		temp = n - (i - (lower_bound(a+1, a+n+1, a[i]-n+1) - a) + 1);
		if (lower_bound(a+1, a+n+1, a[i]-n+1) == upper_bound(a+1, a+n+1, a[i]-n+1) && temp == 1)
			temp++;
		ans = min(ans, temp);
		temp = n - ((upper_bound(a+1, a+n+1, a[i]+n-1) - a) - i);
		if (lower_bound(a+1, a+n+1, a[i]+n-1) == upper_bound(a+1, a+n+1, a[i]+n-1) && temp == 1)
			temp++;
		ans = min(ans, temp);
	}
	cout << ans << '\n';
	cout << max(a[n-1] - a[1] + 1 - (n-1), a[n] - a[2] + 1 - (n-1)) << '\n';
	return 0;
}

