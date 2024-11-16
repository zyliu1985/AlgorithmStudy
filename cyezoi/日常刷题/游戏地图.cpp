#include <iostream>
#include <cstring>
using namespace std;

struct node{
	int m, z;
};
char c[1005][10005];
bool vis[1005][10005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
node ans;
node max(node x, node y){
	if (x.m > y.m) return x;
	if (x.m < y.m) return y;
	if (x.z < y.z) return x;
	if (x.z > y.z) return y;
}
node dfs(int x, int y){
	int rem = 1, rez = 0;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (c[nx][ny] == '#'){
			if (!vis[nx][ny]){
				node t = dfs(nx, ny);
				rem += t.m;
				rez += t.z;
			}
		} else rez++;
	}
	return {rem, rez};
}
int main(){
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		m = s.size();
		for (int j = 0; j < m; j++)
			c[i][j+1] = s[j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (c[i][j] == '#' && !vis[i][j]) ans = max(ans, dfs(i, j));
	cout << ans.m << ' ' << ans.z << endl;
	return 0;
}