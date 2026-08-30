#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans[60005], d[60005];
vector<int> v[60005];
void dfs(int x, int fa){
	d[x] = d[fa] + 1;
	ans[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			dfs(v[x][i], x);
			ans[x] += ans[v[x][i]];
		}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	d[1] = 1;
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ' << d[i] << '\n';
	
	return 0;
}



