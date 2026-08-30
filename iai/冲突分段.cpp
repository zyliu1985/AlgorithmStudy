#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int a[100005];
int l = 1, r = 1;
long long sum;
int cnt[100005];
bool now = 0;
long long calc(int ql, int qr){
	while (r < qr) sum += cnt[a[++r]]++;
	while (ql < l) sum += cnt[a[--l]]++;
	while (qr < r) sum -= --cnt[a[r--]];
	while (l < ql) sum -= --cnt[a[l++]];
	return sum;
}
long long dp[100005][2];
void solve(int cl, int cr, int ql, int qr){
	if (cl > cr) return;
	int mid = (cl + cr) / 2;
//	cout << mid << ':' << ql << ' ' << qr << '\n';
	dp[mid][now] = 1e18;
	int nowq;
	for (int i = ql; i <= min(qr, mid-1); i++){
		if (dp[i][now^1] + calc(i+1, mid) < dp[mid][now]){
			nowq = i;
			dp[mid][now] = dp[i][now^1] + calc(i+1, mid);
		}
	}
//	cout << mid << ": " << dp[mid][now] << " from " << nowq << ": " << dp[nowq][now^1] << '+' << calc(nowq+1, mid) << '\n';
	solve(cl, mid-1, ql, nowq);
	solve(mid+1, cr, nowq, qr);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	k--;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cnt[a[1]]++;
	for (int i = 2; i <= n; i++)
		dp[i][now] = calc(1, i);
	for (int i = 1; i <= k; i++){
//		cout << "--------- " << i << " ---------\n";
		now ^= 1;
		solve(2, n, 1, n);
	}
	cout << dp[n][now] << '\n';
	return 0;
}

