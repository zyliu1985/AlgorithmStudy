#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

long long a[1005], c[1005][1005];

long long jc(int n) {
	long long rv = 1;
	for(int i = 1; i<=n; i++) {
		rv*=i;
	}
	return rv % 998244353;
}
//
//
//// 根据符合范围的数计算组合情况 C(n,m)
//long long com(int n, int m) {
//	if(n < 0 || m < 0) return 0;
//	if(n < m) return 0;
//	if(n == m) return 1;
//	long long rv = jc(n)/jc(m)/jc(n-m);
////	cout << "rv =" << rv << endl;
//	return rv % 998244353;
//}

int main(){
	int n, m, k, X;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	cin >> k >> X;
	
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <=i; j++) {
			if(!j) c[i][j]=1;
			else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % 998244353;
			cout << "i=" << i << ",j=" << j <<",c[i][j]=" << c[i][j] << endl;
		}
	}
	
	long long ans = 0;
	
	sort(a+1, a+n+1);
	
	int ltc = lower_bound(a+1, a+n+1, X) - a - 1;
	int btc = n - ltc;
	
//	cout << "ltc=" << ltc << ", btc=" << btc << endl;
	
	for(int i = k; i<=m && i <= btc; i++) {
//		ans += (com(btc, i) * com(ltc, m-i)) % 998244353;

		ans += (c[btc][i]*c[ltc][m-i])% 998244353;
		ans %= 998244353;
	}
	
	cout << ans << endl;
	return 0;
}