#include <iostream>
using namespace std;

int ans, n;
char c[15][15];
int vis[15][15];
void set(int x, int y, int val){
	for (int i = x; i <= n; i++) vis[i][y] += val;
	for (int i = x, j = y; i <= n && j >= 1; i++, j--) vis[i][j] += val;
	for (int i = x, j = y; i <= n && j <= n; i++, j++) vis[i][j] += val;
}
void dfs(int step){
//	cout << step << endl;
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++)
//			cout <<vis[i][j];
//		cout << endl;
//	}
	if (step > n){
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (vis[step][i] == 0 && c[step][i] != '.'){
			set(step, i, 1);
			dfs(step+1);
			set(step, i, -1);
		}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	dfs(1);
	cout << ans << endl;
	return 0;
}