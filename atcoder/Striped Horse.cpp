#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long d[400005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, w;
		cin >> n >> w;
		for (int i = 0; i <= 2 * w; i++)
			d[i] = 0;
		for (int i = 1; i <= n; i++){
			int c;
			cin >> c;
			int l = (i % (2 * w) + w + 1) % (2 * w);
			int r = i % (2 * w);
			if (l <= r){
				d[l] += c;
				d[r+1] -= c;
			} else {
				d[l] += c;
				d[2*w] -= c;
				d[0] += c;
				d[r+1] -= c;
			}
		}
		long long now = 0;
		long long ans = 1e18;
		for (int i = 0; i <= 2*w-1; i++){
			now += d[i];
			ans = min(ans, now);
		}
		cout << ans << '\n';
	} 
	return 0;
}

