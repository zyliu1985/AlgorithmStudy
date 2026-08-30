#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[305][305];
vector<int> v[305];
int s[305];
void dfs(int x){
	for (int i = 0; i < v[x].size(); i++){
		dfs(v[x][i]);
		for (int j = 300; j >= 1; j--)
			for (int w = 1; w <= j; w++)
				dp[x][j] = max(dp[x][j], dp[x][j-w] + dp[v[x][i]][w-1] + s[v[x][i]]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int f;
		cin >> f >> s[i];
		v[f].push_back(i);
	}
	dfs(0);
	cout << dp[0][m] << '\n';
	return 0;
}

