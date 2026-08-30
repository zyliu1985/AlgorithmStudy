#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int h[5005], ans[5005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(ans, 0x3f, sizeof(ans));
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	// 单个扩展
	for (int i = 1; i <= n; i++){
		int now = 0;
		for (int l = i, r = i; l >= 1 && r <= n; l--, r++){
			now += abs(h[r] - h[l]);
			ans[r - l + 1] = min(ans[r - l + 1], now);
		}
	}
	// 双个扩展 (i, i+1)
	for (int i = 1; i < n; i++){
		int now = 0;
		for (int l = i, r = i+1; l >= 1 && r <= n; l--, r++){
			now += abs(h[r] - h[l]);
			ans[r - l + 1] = min(ans[r - l + 1], now);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	return 0;
}
