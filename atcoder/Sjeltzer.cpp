#include <iostream>
#include <algorithm>
using namespace std;

long long dp[7][1000000];
int get(int x, int pos){
	pos = 6 - pos;
	while (pos--) x /= 10;
	return x % 10;
}
int change(int x, int pos, int d){
	int num = get(x, pos);
	pos = 6 - pos;
	while (pos--) num *= 10, d *= 10;
	x = x - num + d;
	return x;
}
int calc(int x){
	int re = 0;
	while (x > 0){
		re++;
		x -= (x&-x);
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x, v;
		cin >> x >> v;
		dp[0][x] += v; 
	}
	for (int i = 1; i <= 6; i++)
		for (int x = 0; x < 1000000; x++){
			int now = get(x, i);
			for (int d = 0; d <= now; d++)
					dp[i][x] += dp[i-1][change(x, i, d)];
		}
	int q;
	cin >> q;
	while (q--){
		int l, r;
		cin >> l >> r;
		bool cont = 0;
		for (int i = 1; i <= 6; i++){
			if (get(l, i) > get(r, i)){
				cout << 0 << '\n';
				cont = 1;
				break;
			}
		}
		if (cont) continue;
		long long ans = 0;
//		for (int i = 1; i <= 6; i++){
//			if (get(l, i)){
//				int cg1 = change(r, i, get(l, i) - 1);
//				ans -= dp[6][cg1];
//				for (int j = i+1; j <= 6; j++){
//					if (get(l, j)){
//						int cg2 = change(cg1, j, get(l, j) - 1);
//						ans += dp[6][cg2];
//						for (int k = )
//					}
//				}
//			}
//		}
		for (int i = 0; i < (1 << 6); i++){
			int now = r;
			bool flag = false;
			for (int j = 1; j <= 6; j++)
				if ((i >> (j-1)) & 1){
					if (get(l, j)){
						now = change(now, j, get(l, j) - 1);
					} else {
						flag = true;
					}
				}
			if (flag) continue;
//			cout << "change:" << ((calc(i) & 1) ? -1 : 1) * dp[6][now] << '\n';
			ans += ((calc(i) & 1) ? -1 : 1) * dp[6][now];
		}
		if (ans > 0) cout << ans << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}

