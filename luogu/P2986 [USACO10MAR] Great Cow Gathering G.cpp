#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long c[100005], sumc[100005], dp[100005], ans = 1e18;
vector<int> v[100005], l[100005];
void up(int x, int fa){
	sumc[x] = c[x];
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] != fa){
			up(v[x][i], x);
			dp[x] = dp[x] + dp[v[x][i]] + sumc[v[x][i]] * l[x][i];
			sumc[x] += sumc[v[x][i]];
		}
	}
}
void down(int x, int fa, int len){
	if (fa != 0){
		dp[x] += dp[fa] - dp[x] - sumc[x] * len + (sumc[1] - sumc[x]) * len;
	}
	ans = min(ans, dp[x]);
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] != fa){
			down(v[x][i], x, l[x][i]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	for (int i = 1; i < n; i++){
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back(y);
		v[y].push_back(x);
		l[x].push_back(w);
		l[y].push_back(w);
	}
	up(1, 0);
//	for (int i = 1; i <= n; i++)
//		cout << dp[i] << ' ';
//	cout << '\n';
//	
//	for (int i = 1; i <= n; i++)
//		cout << sumc[i] << ' ';
//	cout << '\n';
	down(1, 0, 0);
//	for (int i = 1; i <= n; i++)
//		cout << dp[i] << ' ';
//	cout << '\n';
	cout << ans << '\n';
	return 0;
}

