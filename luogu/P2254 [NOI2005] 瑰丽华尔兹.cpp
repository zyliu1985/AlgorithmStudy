#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;

char c[205][205];
int dp[205][205][205];
struct node{
	int x, id;
};
deque<node> q;
void insert(node x){
	while (!q.empty() && x.x >= q.back().x) q.pop_back();
	q.push_back(x);
}
int query(int l){
	while (!q.empty() && q.front().id < l) q.pop_front();
	return q.front().x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
	memset(dp, 0xc0, sizeof(dp));
	dp[0][x][y] = 0;
	for (int t = 1; t <= k; t++){
		int ts, te, d;
		cin >> ts >> te >> d;
		int maxl = te - ts + 1;
		if (d == 1){
			for (int j = 1; j <= m; j++){
				q.clear();
				for (int i = n; i >= 1; i--){
					if (c[i][j] == 'x'){
						q.clear();
					} else {
						int ti = n-i+1;
						insert(node{dp[t-1][i][j] + n - ti, ti});
						dp[t][i][j] = query(ti - maxl) - (n - ti);
					}
				}
			}
		} else if (d == 2){
			for (int j = 1; j <= m; j++){
				q.clear();
				for (int i = 1; i <= n; i++){
					if (c[i][j] == 'x'){
						q.clear();
					} else {
						int ti = i;
						insert(node{dp[t-1][i][j] + n - ti, ti});
						dp[t][i][j] = query(ti - maxl) - (n - ti);
					}
				}
			}
		} else if (d == 3){
			for (int i = 1; i <= n; i++){
				q.clear();
				for (int j = m; j >= 1; j--){
					if (c[i][j] == 'x'){
						q.clear();
					} else {
						int tj = m-j+1;
						insert(node{dp[t-1][i][j] + n - tj, tj});
						dp[t][i][j] = query(tj - maxl) - (n - tj);
					}
				}
			}
		} else {
			for (int i = 1; i <= n; i++){
				q.clear();
				for (int j = 1; j <= m; j++){
					if (c[i][j] == 'x'){
						q.clear();
					} else {
						int tj = j;
						insert(node{dp[t-1][i][j] + n - tj, tj});
						dp[t][i][j] = query(tj - maxl) - (n - tj);
					}
				}
			}
		}
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= m; j++)
//				cout << dp[t][i][j] << ' ';
//			cout << '\n';
//		}
//		cout << "-----------------\n";
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans = max(ans, dp[k][i][j]);
	cout << ans << '\n';
	return 0;
}

