#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int s[10005], d[10005];
long long dp[500005][2];
bool now; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		d[i] = s[i] - s[i-1];
	}
	sort(d+2, d+n+1);
	s[1] = 0; 
	for (int i = 2; i <= n; i++)
		s[i] = s[i-1] + d[i];
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 2; i <= n; i++){
		if (d[i] == 0) continue;
		for (int j = 5e5; j >= 0; j--){
//			if (dp[j][now] <= 1e10) cout << i-1 << ' ' << j << ':' << dp[j][now] << '\n';
			// ¹È×ó 
			if (j + i * d[i] <= 5e5) dp[j + (i-1) * d[i]][now^1] = min(dp[j + (i-1) * d[i]][now^1], dp[j][now] + 2ll * j * d[i] + (i-1) * 1ll * d[i] * d[i]);
			// ¹ÈÓÒ
			if (j + s[i] <= 5e5) dp[j + s[i]][now^1] = min(dp[j + s[i]][now^1], dp[j][now] + s[i] * 1ll * s[i]);
			dp[j][now] = 1e12;
		}
		now ^= 1;
	}
	long long ans = 1e18;
	for (long long i = 0; i <= 5e5; i++){
//		if (dp[i][now] <= 1e10) cout << n << ' ' << i << ':' << dp[i][now] << '\n';
//		cout << i << ':' << dp[i][now] * n - i * i << '\n'; 
		ans = min(ans, dp[i][now] * n - i * i);
	}
	cout << ans << '\n';
	return 0;
}

