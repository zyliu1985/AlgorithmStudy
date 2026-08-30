#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[60005];
int sz[60005], hv[60005], f[60005];
int n;
int not_hv(int rt, int x){
	if (sz[rt] - sz[x] > sz[rt] / 2) return 1e9;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != f[x] && sz[v[x][i]] > sz[rt] / 2) return v[x][i];
	return 0;
}
void init(int x, int fa){
	f[x] = fa;
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			init(v[x][i], x);
			sz[x] += sz[v[x][i]];
		}
}
void solve(int x, int fa){
//	for (int i = 1; i <= n; i++)
//		cout << hv[i] << ' ';
//	cout << x << ',' << fa << ':' << not_hv(x, x) << '\n'; 
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa)
			solve(v[x][i], x);
	if (!not_hv(x, x)){
		hv[x] = x;
		return;
	} else {
		int now = hv[not_hv(x, x)];
		while (not_hv(x, now))
			now = f[now];
		hv[x] = now;
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
	init(1, 0);
	solve(1, 0);
	for (int i = 1; i <= n; i++)
		cout << hv[i] << '\n';
	return 0;
}
