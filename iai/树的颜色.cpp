#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[200005];
int col[200005], sz[200005];
int cnt[200005], ans[200005];
int heavy[200005];
void init(int x){
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++){
		init(v[x][i]);
		sz[x] += sz[v[x][i]];
		if (sz[v[x][i]] > sz[heavy[x]]) heavy[x] = v[x][i];
	}
}
void update(int x, int type){
	cnt[col[x]] += type;
	for (int i = 0; i < v[x].size(); i++)
		update(v[x][i], type);
}
void dfs(int x, bool keep){
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != heavy[x]){
			dfs(v[x][i], 0);
		}
	if (heavy[x]) dfs(heavy[x], 1);
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != heavy[x]){
			update(v[x][i], 1); 
		}
	ans[x] = cnt[col[x]];
	cnt[col[x]]++;
	if (!keep){
		update(x, -1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n; 
	for (int i = 2; i <= n; i++){
		int f;
		cin >> f;
		v[f].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		cin >> col[i];
	init(1);
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}

