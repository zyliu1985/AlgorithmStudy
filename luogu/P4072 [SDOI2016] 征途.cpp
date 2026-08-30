#include <iostream>
#include <algorithm>
using namespace std;

bool now = 0;
int sum;
int n, m;
long long s[3005];
long long dp[3005][2];
void solve(int cl, int cr, int ql, int qr){
	if (cl > cr) return;
	int mid = (cl + cr) / 2;
	int nowq;
	dp[mid][now] = 1e18;
	for (int i = ql; i <= min(qr, mid-1); i++)
		if (dp[i][now^1] + ((s[mid] - s[i]) * m - sum) * ((s[mid] - s[i]) * m - sum) < dp[mid][now]){
			nowq = i;
			dp[mid][now] = dp[i][now^1] + ((s[mid] - s[i]) * m - sum) * ((s[mid] - s[i]) * m - sum);
		}
	solve(cl, mid-1, ql, nowq);
	solve(mid+1, cr, nowq, qr);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		s[i] = s[i-1] + a;
	}
	sum = s[n];
	for (int i = 1; i <= n; i++)
		dp[i][now] = (s[i] * 1ll * m - sum) * (s[i] * 1ll * m - sum);
//	for (int i = 1; i <= n; i++)
//		cout << dp[i][now] << '\n';
	for (int i = 2; i <= m; i++){
		now ^= 1;
		for (int j = 1; j < i; j++) dp[j][now] = 1e18;
		solve(i, n, 1, n); 
	}
	cout << dp[n][now] / m << '\n';
	return 0;
}

