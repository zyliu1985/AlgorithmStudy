#include <iostream>
#include <algorithm>
using namespace std;

int a[300005], d[300005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a+1, a+n+1);
		int dmax = 0;
		for (int i = 2; i <= n; i++)
			d[i] = a[i] - a[i-1], dmax = max(d[i], dmax);
		int q;
		cin >> q;
		while (q--){
			int i, x;
			cin >> i >> x;
			int cur = lower_bound(a+1, a+n+1, x) - a;
			if (cur > i) cur--;
			
		}
	} 
	return 0;
}



