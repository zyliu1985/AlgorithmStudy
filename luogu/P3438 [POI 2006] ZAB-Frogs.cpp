#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int px, py, kx, ky;
bool mp[1005][1005];
int bad[1005];
int dp[1005][1005];
int dist(int x1, int y1, int x2, int y2){
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
void solve(int l, int r, int ql, int qr, int x){
	if (l > r) return;
	int mid = (l + r) / 2;
	int nown = 1e9, nowq;
	for (int i = ql; i <= qr; i++){
		if (!bad[i]) continue;
		if (dist(bad[i], i, x, mid) < nown){
			nown = dist(bad[i], i, x, mid);
			nowq = i;
		}
	}
	dp[x][mid] = min(dp[x][mid], nown);
	solve(l, mid-1, ql, nowq, x);
	solve(mid+1, r, nowq, qr, x);
}
queue<pair<int, int> > q;
bool vis[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool in(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m; 
}
bool check(int x){
	if (dp[px][py] < x) return false;
	memset(vis, 0, sizeof(vis));
	q.push(make_pair(px, py));
	vis[px][py] = true;
	while (!q.empty()){
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int zx = nx + dx[i];
			int zy = ny + dy[i];
			if (in(zx, zy) && !vis[zx][zy] && dp[zx][zy] >= x){
				q.push(make_pair(zx, zy));
				vis[zx][zy] = true;
			}
		}
	}
	return vis[kx][ky];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(dp, 0x3f, sizeof(dp));
	cin >> n >> m;
	cin >> px >> py >> kx >> ky;
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++){
		int a, b;
		cin >> a >> b;
		mp[a][b] = true;
	}
	bool flag = false;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			if (mp[i][j]) bad[j] = i, flag = true;
		if (flag) solve(1, m, 1, m, i);
	}
	flag = false;
	for (int j = 1; j <= m; j++)
		bad[j] = 0;
	for (int i = n; i >= 1; i--){
		for (int j = 1; j <= m; j++)
			if (mp[i][j]) bad[j] = i, flag = true;
		if (flag) solve(1, m, 1, m, i);
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++)
//			cout << dp[i][j] << ' ';
//		cout << '\n';
//	}
	int l = 0, r = (n-1)*(n-1) + (m-1)*(m-1);
	while (l < r){
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid-1;
	}
	cout << l << '\n';
	return 0;
}
