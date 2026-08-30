#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[10005], w[10005];
int dp1[10005], dp2[10005], maxid[10005];
void dfs1(int x, int fa){
	dp1[x] = dp2[x] = maxid[x] = 0;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dfs1(v[x][i], x);
		if (dp1[v[x][i]] + w[x][i] > dp1[x]){
			dp2[x] = dp1[x];
			dp1[x] = dp1[v[x][i]] + w[x][i];
			maxid[x] = v[x][i];
		} else if (dp1[v[x][i]] + w[x][i] > dp2[x])
			dp2[x] = dp1[v[x][i]] + w[x][i];
	}
}
void dfs2(int x, int fa, int l){
	if (x > 1){
		int upd;
		if (maxid[fa] == x){
			upd = dp2[fa] + l;
		} else {
			upd = dp1[fa] + l;
		}
		if (upd > dp1[x]){
			dp2[x] = dp1[x];
			dp1[x] = upd;
			maxid[x] = fa;
		} else if (upd > dp2[x])
			dp2[x] = upd;
	}
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dfs2(v[x][i], x, w[x][i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	while (cin >> n){
		for (int i = 1; i <= n; i++)
			v[i].clear(), w[i].clear();
		for (int i = 2; i <= n; i++){
			int a, b;
			cin >> a >> b;
			v[i].push_back(a);
			v[a].push_back(i);
			w[i].push_back(b);
			w[a].push_back(b);
		}
		dfs1(1, 0);
		dfs2(1, 0, 0);
		for (int i = 1; i <= n; i++)
			cout << dp1[i] << '\n';
	}
	return 0;
}

