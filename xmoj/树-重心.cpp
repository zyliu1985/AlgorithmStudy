#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[60005];
int sz[60005];
int n;
int ans1, ans2;
void dfs(int x, int fa){
	bool flag = true;
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			dfs(v[x][i], x);
			sz[x] += sz[v[x][i]];
			if (sz[v[x][i]] > n / 2) flag = false;
		}
	if (n - sz[x] > n / 2) flag = false;
	if (flag){
		if (ans1){
			if (ans1 > x){
				ans2 = ans1;
				ans1 = x;
			}
		} else {
			ans1 = x;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	v[x].push_back(y);
    	v[y].push_back(x);
	}
	dfs(1, 0);
	if (ans2){
		cout << ans1 << '\n' << ans2 << '\n';
	} else {
		cout << ans1 << '\n';
	}
	return 0;
}
