#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 3e3 + 110;
ll n, m, a[maxn], b[maxn], c[maxn], f[maxn], ans = -1, kk = 0, s[maxn];

ll check(){
	memset(f, -1, sizeof(f));
	f[1] = c[1];
	for (int i = 2; i <= n + m; i++){
		f[i] = max(f[i - 1], f[i - 2] + c[i]);
	}
	return f[n + m];
}

void dfs(ll x, ll pos, ll cnt){
	s[pos] = x;
	if (cnt >= m){
		ll k = 0;
		for (int i = 0; i <= n; i++){
			c[i + k] = a[i];
			if (s[i]){
				k++;
				c[i + k] = s[i];
			}
		}
		ans = max(ans, check());
		return;
	}
	for (int i = 0; i <= n; i++){
		if (s[i]) continue;
		dfs(b[cnt + 1], i, cnt + 1);
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	a[0] = 0;
	f[0] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}
