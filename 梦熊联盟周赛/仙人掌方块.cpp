#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<char> mp[200005], ans[200005];
int mina = 1e9;
vector<bool> vis[200005];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};
bool in(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}
void dfs(int x, int y, int num){
//	cout << x << ' ' << y << ' ' << num << endl;
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++)
//			cout << mp[i][j];
//		cout << endl;
//	}
	if (x > 0)
		if (mp[x-1][y] == '#') return;
	if (x < n-1)
	    if (mp[x+1][y] == '#') return;
	if (y > 0)
	    if (mp[x][y-1] == '#') return;
	if (y < m-1)
		if (mp[x][y+1] == '#') return;
	bool flag = false;
	vis[x][y] = true;
	if (mp[x][y] == '.'){
		mp[x][y] = '#';
		flag = true;
		num++;
	}
	if (y == m-1){
		if (num < mina){
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					ans[i][j] = mp[i][j];
			mina = num;
		}
		return;
	}
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!in(nx, ny)) continue;
		if (vis[nx][ny]) continue;
		dfs(nx, ny, num);
	}
	if (flag) mp[x][y] = '.';
}
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				char c;
				cin >> c;
				mp[i].push_back(c);
			}
			ans[i].resize(m);
			vis[i].resize(m);
		}
		for (int i = 0; i < n; i++)
			if (!vis[i][0])
				dfs(i, 0, 0);
		if (mina != 1e9){
			cout << "Yes" << endl;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++)
					cout << ans[i][j];
				cout << endl;
				mp[i].resize(0);
				vis[i].resize(0);
				ans[i].resize(0);
			}
		} else {
			cout << "No" << endl;
			for (int i = 0; i < n; i++){
				mp[i].resize(0);
				vis[i].resize(0);
				ans[i].resize(0);
			}
		}
		mina = 1e9;
	}
	return 0;
}