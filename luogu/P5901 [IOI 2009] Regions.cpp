#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int big = 500;
int col[200005];
vector<int> v[200005];

int cnt[25005], ans1[55][25005], ans2[25005][55];
int id, big_id[25005];

int cur;
vector<int> dfn[200005], ed[200005];
// calc cnt, dfn, ed
int dfs(int x){
	cnt[col[x]]++;
	cur++;
	dfn[col[x]].push_back(cur);
	int x_ed = cur;
	for (int i = 0; i < v[x].size(); i++)
		x_ed = max(x_ed, dfs(v[x][i]));
	ed[col[x]].push_back(x_ed);
	return x_ed;
}
void calc_ans1(int x, int cl, int flag){
	if (big_id[col[x]] == cl){
		flag++;
	} else {
		ans1[cl][col[x]] += flag;
	}
	for (int i = 0; i < v[x].size(); i++)
		calc_ans1(v[x][i], cl, flag);
}
int calc_ans2(int x, int cl){
	int num = 0;
	for (int i = 0; i < v[x].size(); i++)
		num += calc_ans2(v[x][i], cl);
	if (big_id[col[x]] == cl){
		num++;
	} else {
		ans2[col[x]][cl] += num;
	}
	return num;
}
int main(){
	int n, r, q;
	cin >> n >> r >> q;
	cin >> col[1];
	for (int i = 2; i <= n; i++){
		int fa;
		cin >> fa >> col[i];
		v[fa].push_back(i);
	}
	dfs(1);
	// calc big_id
	for (int i = 1; i <= r; i++)
		if (cnt[i] >= big)
			big_id[i] = ++id;
	for (int i = 1; i <= id; i++){
		calc_ans1(1, i, false);
		calc_ans2(1, i);
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		if (big_id[x]){
			cout << ans1[big_id[x]][y] << endl;
		} else if (big_id[y]){
			cout << ans2[x][big_id[y]] << endl;
		} else {
			// dfn[x][i], dfn[y][j], ed[x][i]
			int j = 0;
			long long stp1 = 0;
			for (int i = 0; i < ed[x].size(); i++){
				while (j < dfn[y].size() && dfn[y][j] <= ed[x][i]) j++;
				stp1 += j-1;
			}
			j = 0;
			long long stp2 = 0;
			for (int i = 0; i < dfn[x].size(); i++){
				while (j < dfn[y].size() && dfn[y][j] < dfn[x][i]) j++;
				stp2 += j-1;
			}
			cout << stp1 - stp2 << endl;
		}
	}
	return 0;
}

