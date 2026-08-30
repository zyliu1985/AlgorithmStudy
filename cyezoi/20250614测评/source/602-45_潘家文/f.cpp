#include <bits/stdc++.h>
#define dp(i, j, k, l) (j < 0 || k < 0 ? 0 : _dp[i][j][k][l])
using namespace std;
using ll = long long;
using lll = __int128;
using ull= unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f, N = 3e3, M = 100;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
int n, m, a[N + 5], b[M + 5], _dp[N + 5][M + 5][M + 5][2], ans;

int tmax(int a, int b, int c){
	if(a >= b && a >= c) return a;
	else if(b >= a && b >= c) return b;
	else return c;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	cin >> m;
	for(int i = 1; i <= m; ++ i) cin >> b[i];
	sort(b + 1, b + m + 1, greater<int>());
	for(int i = 1; i <= n; ++ i) for(int j = 0; j <= m; ++ j) for(int k = 0; k <= m - j; ++ k){
		_dp[i][j][k][0] = tmax(dp(i - 1, j, k, 0), dp(i - 1, j, k, 1), tmax(dp(i - 1, j - 1, k, 0) + b[j], dp(i, j, k - 1, 0), dp(i, j, k - 1, 1)));
		_dp[i][j][k][1] = max(tmax(dp(i - 1, j, k, 0), dp(i - 1, j, k - 1, 0), dp(i - 1, j, k - 1, 1)) + a[i], dp(i, j - 1, k, 0) + b[j]);
//		if(dp(i, j, k, 0) > ans) cout << i << ' ' << j << ' ' << k << " 0: " << dp(i, j, k, 0) << endl;
//		if(dp(i, j, k, 1) > ans) cout << i << ' ' << j << ' ' << k << " 1: " << dp(i, j, k, 1) << endl;
		ans = tmax(ans, dp(i, j, k, 0), dp(i, j, k, 1));
	}
	cout << ans;
}

