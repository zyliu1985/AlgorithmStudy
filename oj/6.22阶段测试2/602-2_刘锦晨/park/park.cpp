#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int y[100005], x[100005], c[100005];
int main(){
	freopen("park.in", "r", stdin);
	freopen("park.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> y[i];
	for (int j = 1; j <= m; j++)
		cin >> x[j];
	bool flag = true;
	for (int j = 1; j <= m; j++){
		cin >> c[j];
		if (c[j] != 0) flag = false;
	}
	if (n <= 1000 && m <= 1000){
		for (int i = 1; i <= n; i++){
			int ans = 1e9;
			for (int j = 1; j <= m; j++)
				ans = min(ans, abs(x[j] - y[i]) + c[j]);
			cout << ans << ' ';
		}
	} else if (flag){
		for (int i = 1; i <= n; i++){
			int t = lower_bound(x+1, x+m+1, y[i]) - x;
			int ans = 1e9;
			if (t != m+1) ans = min(ans, x[t] - y[i] + c[t]);
			if (t != 1) ans = min(ans, y[i] - x[t-1] + c[t-1]);
			cout << ans << ' ';
		}
	} else {
		int mu, minn = 1e9;
		for (int i = 1; i <= m; i++)
			if (x[i] + c[i] < minn){
				minn = x[i] + c[i];
				mu = i;
			}
		for (int i = 1; i <= n; i++)
			cout << x[mu] - y[i] + c[mu] << ' ';
	}
	return 0;
}
