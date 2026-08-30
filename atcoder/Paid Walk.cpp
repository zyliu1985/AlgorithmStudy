#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[200005], w[200005];
int n, m, l, s, t;
bool ans[200005];
void dfs(int x, int stp, int sum){
	if (stp == l){
		if (s <= sum && sum <= t)
			ans[x] = true;
		return;
	}
	for (int i = 0; i < v[x].size(); i++)
		dfs(v[x][i], stp+1, sum+w[x][i]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> l >> s >> t;
	for (int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(b);
		w[a].push_back(c);
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++)
		if (ans[i]) cout << i << ' ';
	cout << '\n';
	return 0;
}

