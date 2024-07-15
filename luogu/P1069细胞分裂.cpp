#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

long long a[10005], yin[3505], yin2[3505], cnt;
long long zh[3505], ans = 8e18, m1, m2;
bool zhi(int x){
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return false;
	return true;
}
void chai1(int x){
	for (int i = 1; i <= cnt; i++){
		if (x % zh[i] == 0){
			while (x % zh[i] == 0)
				yin[i]++, x /= zh[i];
			yin[i] *= m2;
		}
		if (x == 1) break;
	}
}
void chai2(int x){
	memset(yin2, 0, sizeof(yin2));
	for (int i = 1; i <= cnt; i++){
		if (x % zh[i] == 0){
			while (x % zh[i] == 0)
				yin2[i]++, x /= zh[i];
		}
		if (x == 1) break;
	}
}
int main(){
//	freopen("P1069_5.in", "r", stdin);
//	freopen("cell.out", "w", stdout);
	int n;
	cin >> n;
	cin >> m1 >> m2;
	for (int i = 2; i <= m1; i++)
		if (zhi(i))
			zh[++cnt] = i;
	chai1(m1);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		chai2(a[i]);
		long long sum = 0;
		bool flag = false;
		for (int j = 1; j <= cnt; j++)
			if (yin2[j] == 0 && yin[j] > 0){
				flag = true;
				break;
			} else if (yin[j] >= yin2[j])
				sum = max(sum, (long long)(ceil(1.0 * yin[j] / yin2[j])));
		if (flag) continue;
		ans = min(ans, sum);
	}
	if (ans == 8e18) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}