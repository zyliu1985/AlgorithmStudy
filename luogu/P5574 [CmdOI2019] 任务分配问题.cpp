#include <iostream>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;

bool now = 0;
int n, k;
int a[25005];
int l = 1, r = 1;
int sum, cnt;
int tr[25005];
int dp[25005][2];
void add(int x, int c){
	for (int i = x; i <= n; i += lowbit(i))
		tr[i] += c;
}
void insert(int x){add(x, 1), cnt++;}
void del(int x){add(x, -1), cnt--;}
int query_lower(int x){
	int re = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		re += tr[i];
	return re;
}
int query_upper(int x){
	return cnt - query_lower(x);
}
int calc(int ql, int qr){
	while (r < qr) r++, sum += query_lower(a[r]), insert(a[r]);
	while (l > ql) l--, sum += query_upper(a[l]), insert(a[l]);
	while (qr < r) del(a[r]), sum -= query_lower(a[r]), r--;
	while (ql > l) del(a[l]), sum -= query_upper(a[l]), l++;
	return sum;
}
void solve(int cl, int cr, int ql, int qr){
	if (cl > cr) return;
	int mid = (cl + cr) / 2;
	int nowq = 1;
	dp[mid][now] = 1e9;
	for (int i = ql; i <= min(qr, mid-1); i++)
		if (dp[i][now^1] + calc(i+1, mid) < dp[mid][now]){
			dp[mid][now] = dp[i][now^1] + calc(i+1, mid);
			nowq = i;
		}
//	cout << mid << ": " << dp[mid][now] << " from " << nowq << '\n';
	solve(cl, mid-1, ql, nowq);
	solve(mid+1, cr, nowq, qr);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	insert(a[1]);
	for (int i = 1; i <= n; i++)
		dp[i][now] = calc(1, i);
//	for (int i = 1; i <= n; i++)
//		cout << dp[i][now] << ' ';
//	cout << '\n';
	for (int i = 2; i <= k; i++){
		now ^= 1;
		solve(1, n, 1, n);
	}
	cout << dp[n][now] << '\n';
	return 0;
}

