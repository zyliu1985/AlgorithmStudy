#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
int v[205][205];
bool vis[205][2], matched[205][2];
bool dfs(int x, bool c){
	vis[x][c] = 1;
	if (c){
		if (!matched[x][c]) return matched[x][c] = true;
		for (int i = 1; i <= n; i++)
			if (v[i][x] == 2 && !vis[i][0]){
				if (dfs(i, 0)){
					v[i][x] = 1;
					return true;
				}
			}
	} else {
		for (int i = 1; i <= n; i++)
			if (v[x][i] == 1 && !vis[i][1]){
				if (dfs(i, 1)){
					v[x][i] = 2;
					return true;
				}
			}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> v[i][j];
		int ans = 0;
		for (int j = 1; j <= n; j++)
			matched[j][0] = matched[j][1] = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
				vis[j][0] = vis[j][1] = 0;
			for (int j = i; j <= n; j++)
				if (!matched[j][0]){
					ans += (matched[j][0] = dfs(j, 0));
				}
		}
		if (ans == n) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}

