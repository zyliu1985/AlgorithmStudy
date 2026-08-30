#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> 
using namespace std;

int n, m;
int v[15][15];
int dp[15][1 << 12];
void print(int x){
	for (int i = 1; i <= n; i++){
		cout << (x & 1) << ' ';
		x >>= 1;
	}
}
bool get(int x, int pos){
	return ((x >> pos-1) & 1);
}
int nw[15];
void dfs(int step, int lv, int x, int sum){
	if (step > n){
		dp[lv+1][x] = min(dp[lv+1][x], sum);
		return;
	}
	if (nw[step] > 5e8) dfs(step+1, lv, x, sum);
	else{
		dfs(step+1, lv, x, sum);
		dfs(step+1, lv, x|(1 << step-1), sum + lv * nw[step]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(v, 0x3f, sizeof(v));
	for (int i = 1; i <= m; i++){
		int a, b, l;
		cin >> a >> b >> l;
		v[a][b] = min(v[a][b], l);
		v[b][a] = min(v[b][a], l);
	}
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++)
		dp[1][1 << i-1] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < (1 << n); j++){
			if (dp[i][j] > 5e8) continue;
//			cout << i << ", ";
//			print(j);
//			cout << ": " << dp[i][j] << '\n';
			for (int k = 1; k <= n; k++)
				nw[k] = 1e9;
			for (int k = 1; k <= n; k++)
				if (get(j, k)){
					for (int t = 1; t <= n; t++)
						if (v[k][t] <= 5e5 && !get(j, t)){
							nw[t] = min(nw[t], v[k][t]);
						} 
				}
			dfs(1, i, j, dp[i][j]);
		}
	int ans = 1e9;
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[i][(1 << n) - 1]);
	cout << ans << '\n';
	return 0;
}

