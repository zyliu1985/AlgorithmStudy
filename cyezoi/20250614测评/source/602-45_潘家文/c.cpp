#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
using ull= unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f, N = 5e3;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
ll ans = INFLL, dp[N + 5][N + 5];
int n, h[N + 5], l, r;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cout << 0 << ' ';
	if(n == 1) return 0;
	for(int i = 1; i <= n; ++ i){
		cin >> h[i];
		if(i > 1) ans = min(ans, (dp[i - 1][i] = abs(h[i] - h[i - 1])));
	}
	cout << ans << ' ';
	for(int len = 3; len <= n; ++ len){
		ans = INFLL;
		for(l = 1; l <= n - len + 1; ++ l){
			r = l + len - 1;
			ans = min(ans, (dp[l][r] = dp[l + 1][r - 1] + abs(h[l] - h[r])));
		}
		cout << ans << ' ';
	}
}

