#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int d[4][2] = {
	{
		1, 0
	},{
		-1, 0
	},{
		0, 1
	},{
		0, -1
	}
};
int n = 2, m, cnt, ls[10][200020];
bool route[10][200020];
inline void dfs(int x, int y) {
	route[x][y] = 1, cnt ++;
	for (int i = 0; i < 4; i ++) {
		int xx = x + d[i][0], yy = y + d[i][1];
		if (xx < 1 || xx > n || yy < 1 || yy > m || route[xx][yy] || ! ls[xx][yy])
			continue;
		dfs(xx, yy);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++)
			cin >> ls[i][j];
	}
	ll answer = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (! route[i][j] && ls[i][j]) {
				cnt = 0;
				dfs(i, j);
				answer += cnt * 3 - (cnt - 1) * 2;
			}
		}
	}
	cout << answer;
}
