#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxm = 1e4 + 10, maxn = 2e3 + 10;
ll k, n, m, A, B, t[maxn][maxn], h[maxn][maxn], ans = 2147483647;
bool vis[maxn];

void dfs(ll x, ll T){
	vis[x] = 1;
	if (x == B){
		ans = min(ans, T);
	}
	for (int i = 1; i <= n; i++){
		if (t[x][i] != -1 && h[x][i] < k && !vis[i]){
			dfs(i, T + t[x][i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(t, -1, sizeof(t));
	memset(h, -1, sizeof(h));
	
	cin >> k >> n >> m;
	for (int i = 1, a, b, tt, hh; i <= m; i++){
		cin >> a >> b >> tt >> hh;
		t[a][b] = t[b][a] = tt;
		h[a][b] = h[b][a] = hh;
	}
	cin >> A >> B;
	dfs(A, 0);
	if (ans == 2147483647) cout << -1;
	else cout << ans;
	return 0;
}
