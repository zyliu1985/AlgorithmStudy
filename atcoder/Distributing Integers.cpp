#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
vector<int> v[200005];
long long dp[200005];
int sz[200005];
int qpow(long long x, int up){
	if (up == 0) return 1;
	if (up & 1) return qpow(x * x % mod, up / 2) * x % mod;
	else return qpow(x * x % mod, up / 2);
}
int inv(long long x){
	return qpow(x, mod - 2);
}
long long frac[200005];
int C(int n, int m){ // n÷–—°m 
	return (frac[n] * inv(frac[n-m]) % mod) * inv(frac[m]) % mod;
}
void dfs1(int x, int fa){
	dp[x] = 1;
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dfs1(v[x][i], x);
		dp[x] = (dp[x] * dp[v[x][i]]) % mod;
		sz[x] += sz[v[x][i]];
	}
	int nowsz = sz[x] - 1;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dp[x] = (dp[x] * C(nowsz, sz[v[x][i]])) % mod;
		nowsz -= sz[v[x][i]];
	}
}
void dfs2(int x, int fa){
	if (x > 1){
		dp[x] = (dp[x] * ((dp[fa] * inv(dp[x]) % mod) * inv(C(sz[1]-1, sz[x])) % mod)) % mod;
		dp[x] = (dp[x] * C(sz[1]-1, sz[1] - sz[x])) % mod;
	}
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dfs2(v[x][i], x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	frac[0] = 1;
	for (int i = 1; i <= n; i++)
		frac[i] = (frac[i-1] * i) % mod;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
		cout << dp[i] << '\n';
	return 0;
}

