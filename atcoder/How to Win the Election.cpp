#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	long long val;
	int id;
} a[200005];
long long s[200005];
int n, m;
int pos[200005];
long long k;
long long ans[200005];
bool cmp(node x, node y){
	return x.val < y.val;
}
bool check(long long num, int id, long long added){
	int t = upper_bound(a+1, a+n+1, node{num, 0}, cmp) - a - 1;
	if (n-t >= m) return false;
	int l = t - (m-(n-t)) + 1;
	if (l <= pos[id]) l--;
	if (l < 1) return true;
	long long sum = s[t] - s[l-1];
	long long need = (num+1) * (t - l + 1);
	if (l <= pos[id]) sum -= a[pos[id]].val, need -= num+1;
	return ((k - added) < (need - sum));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i].val;
		k -= a[i].val;
		a[i].id = i;
	}
	sort(a+1, a+n+1, cmp);
	for (int i = 1; i <= n; i++)
		s[i] = s[i-1] + a[i].val, pos[a[i].id] = i;
	for (int i = 1; i <= n; i++){
		long long l = 0, r = k+1;
		while (l < r){
			long long mid = (l + r) / 2;
			if (check(a[i].val + mid, a[i].id, mid)) r = mid;
			else l = mid + 1;
		}
		if (l == k + 1) ans[a[i].id] = -1;
		else ans[a[i].id] = l;
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	return 0;
}

