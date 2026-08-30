#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[100005];
int maxd[100005], maxs[100005];
void dfs(int x, int fa){
	int maxd2 = 0;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dfs(v[x][i], x);
		maxs[x] = max(maxs[x], maxs[v[x][i]]);
		if (maxd[v[x][i]] + 1 > maxd[x]){
			maxd2 = maxd[x];
			maxd[x] = maxd[v[x][i]] + 1;
		} else if (maxd[v[x][i]] + 1 > maxd2){
			maxd2 = maxd[v[x][i]] + 1;
		}
	}
	maxs[x] = max(maxs[x], maxd[x] + maxd2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	cout << maxs[1] << '\n';
	return 0;
}

