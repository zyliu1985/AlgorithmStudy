#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int val[6005], dp[6005][2];
vector<int> v[6005], ch[6005];
void dfs(int x, int fa){
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			ch[x].push_back(v[x][i]);
			dfs(v[x][i], x);
		}
}
void adp(int x, bool is_chosen){
	if (dp[x][is_chosen]) return;
	dp[x][is_chosen] = val[x] * is_chosen;
	if (ch[x].empty()) return;
	if (is_chosen){
		for (int i = 0; i < ch[x].size(); i++){
			adp(ch[x][i], 0);
			dp[x][is_chosen] += dp[ch[x][i]][0];
		}
	} else {
		for (int i = 0; i < ch[x].size(); i++){
			adp(ch[x][i], 0);
			adp(ch[x][i], 1);
			dp[x][is_chosen] += max(dp[ch[x][i]][0], dp[ch[x][i]][1]);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> val[i];
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0); 
	adp(1, 1);
	adp(1, 0);
	cout << max(dp[1][1], dp[1][0]) << '\n';
	return 0;
}



