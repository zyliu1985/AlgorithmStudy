#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mod;
vector<int> v[100005];
vector<long long> fm[100005], bm[100005];
long long dp[100005];
void dfs1(int x, int fa){
	dp[x] = 1;
	fm[x].resize(v[x].size()); 
	bm[x].resize(v[x].size());
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dfs1(v[x][i], x);
		dp[x] = (dp[x] * dp[v[x][i]]) % mod;
	}
	dp[x] = (dp[x] + 1) % mod;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa){
			if (i == 0) fm[x][i] = 1;
			else fm[x][i] = fm[x][i-1];
		} else {
			if (i == 0) fm[x][i] = dp[v[x][i]];
			else fm[x][i] = (fm[x][i-1] * dp[v[x][i]]) % mod;
		}
	}
	if (v[x].size() > 0){
		for (int i = v[x].size()-1; i >= 0; i--){
			if (v[x][i] == fa){
				if (i == v[x].size()-1) bm[x][i] = 1;
				else bm[x][i] = bm[x][i+1];
			} else {
				if (i == v[x].size()-1) bm[x][i] = dp[v[x][i]];
				else bm[x][i] = (bm[x][i+1] * dp[v[x][i]]) % mod;
			}
		}
	}
}
void dfs2(int x, int fa, long long lst){
	if (x > 1){
		dp[x] = (((dp[x] + mod - 1) % mod) * lst % mod + 1) % mod;
	}
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		long long nxt = 1;
		if (i > 0) nxt = nxt * fm[x][i-1] % mod;
		if (i < v[x].size()-1) nxt = nxt * bm[x][i+1] % mod;
		if (lst > 0) nxt = nxt * lst % mod;
		nxt++;
		cout << v[x][i] << ',' << nxt << '\n'; 
		dfs2(v[x][i], x, nxt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n >> mod;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	for (int i = 1; i <= n; i++)
		cout << (dp[i] - 1 + mod) % mod << '\n';
	return 0;
}

