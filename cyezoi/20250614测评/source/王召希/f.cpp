#include <bits/stdc++.h>
using namespace std;
int ans, n, m, a[3010], b[3040];
void dfs(int pos, bool f, int sum){
	if (pos > n) {
		ans = max(ans, sum);
		return ;
	}
	if (f){
		dfs(pos + 1, 0, sum);
	}
	else {
		dfs(pos + 1, 1, sum + a[pos]);
		dfs(pos + 1, 0, sum);
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}
