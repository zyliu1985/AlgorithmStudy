#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> bx[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, k, f = 1;
		cin >> n >> k;
		if (k < 0) f = -1, k = -k;
		for (int i = 0; i < k; i++){
			bx[i].clear();
		}
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			bx[x % k].push_back(x / k);
		}
		for (int i = 0; i < k; i++){
			sort(bx[i].begin(), bx[i].end());
		}
		long long ans = 0;
		for (int i = 0; i < k; i++){
			long long sum = 0;
			if (bx[i].empty()) continue;
			if (f > 0){
				int now = bx[i][0];
				for (int j = 1; j < bx[i].size(); j++){
					now = max(now + 1, bx[i][j]);
					sum += now - bx[i][j];
				}
			} else {
				int now = bx[i][bx[i].size()-1];
				for (int j = int(bx[i].size())-2; j >= 0; j--){
					now = min(now - 1, bx[i][j]);
					sum += bx[i][j] - now;
				}
			}
			ans += sum;
		}
		cout << ans << '\n';
	}
	return 0;
}

