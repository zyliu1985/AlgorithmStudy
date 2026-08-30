#include <iostream>
#include <algorithm>
using namespace std;

int a[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	while (q--){
		int x, y;
		cin >> x >> y;
		int tx = lower_bound(a+1, a+n+1, x) - a;
		int l = 0, r = n;
		while (l < r){
			int mid = (l + r) / 2;
			int ty = upper_bound(a+1, a+n+1, x + y - 1 + mid) - a;
			if (ty - tx > mid) l = mid+1;
			else r = mid;
		}
		cout << x + y - 1 + l << '\n';
	}
	return 0;
}

