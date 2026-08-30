#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int c, w, f;
} a[100005];
bool cmp(node x, node y){
	return x.f > y.f;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, k;
		long long ans = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; i++){
			cin >> a[i].c >> a[i].w >> a[i].f;
		}
		sort(a+1, a+n+1, cmp);
		int lst = 0, maxh = 0;
		for (int i = 1; i <= n; i++){
			if (a[i].c * a[i].w < k - lst){
				lst += a[i].c * a[i].w;
				maxh = max(maxh, a[i].f);
				continue;
			} else {
				a[i].c -= (k - lst) / a[i].w;
				ans += max(maxh, a[i].f);
			}
			int num = a[i].c / (k / a[i].w);
			ans += num * a[i].f;
			lst = a[i].c % (k / a[i].w);
			maxh = a[i].f;
		}
		if (lst != 0){
			ans += maxh;
		}
		cout << ans << '\n';
	}
	return 0;
}

