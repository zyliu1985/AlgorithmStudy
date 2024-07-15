#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

long long yin[5][300005], cnt;
map<long long, int> zhi;
void chai(int id, int x){
	memset(yin[id], 0, sizeof(yin[id]));
	int tx = sqrt(x);
	for (int i = 2; i <= tx; i++){
		if (x % i == 0){
			int ncnt;
			if (zhi[i] != 0) {
				ncnt = zhi[i];
			} else {
				ncnt = ++cnt;
				zhi[i] = ncnt;
			}
			while (x % i == 0) {
				yin[id][ncnt]++;
				x /= i;
			}
		}
		if (x == 1) break;
	}
	if (x != 1){
		int ncnt;
		if (zhi[x] != 0) {
			ncnt = zhi[x];
		} else {
			ncnt = ++cnt;
			zhi[x] = ncnt;
		}
		yin[id][ncnt]++;
	}
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while (n--){
		int a0, a1, b0, b1;
		cin >> a0 >> a1 >> b0 >> b1;
		chai(1, a0);
		chai(2, a1);
		chai(3, b0);
		chai(4, b1);
		long long ans = 1;
		for (int i = 1; i <= cnt; i++)
			if (yin[1][i] == yin[2][i]){
				long long minn = yin[1][i];
				if (yin[3][i] == yin[4][i])
					ans *= yin[3][i] - minn + 1;
				else if (minn > yin[4][i]){
					ans = 0;
					break;
				}
			} else {
				if (yin[3][i] == yin[4][i]){
					long long maxn = yin[3][i];
					if (maxn < yin[2][i]){
						ans = 0;
						break;
					}
				} else if (yin[4][i] != yin[2][i]){
					ans = 0;
					break;
				}
			}
		cout << ans << endl;
	}
	return 0;
}