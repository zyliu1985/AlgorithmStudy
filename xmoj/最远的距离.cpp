#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[60005], w[60005];
int f[60005], u[60005], cf[60005], fi[60005];
void dfs1(int x, int fa){
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			dfs1(v[x][i], x);
			if (f[v[x][i]] + w[x][i] > f[x]){
				cf[x] = f[x];
				f[x] = f[v[x][i]] + w[x][i];
				fi[x] = v[x][i];
			} else if (f[v[x][i]] + w[x][i] > cf[x]){
				cf[x] = f[v[x][i]] + w[x][i];
			}
		}
}
void dfs2(int x, int fa, int faval){
	u[x] = u[fa] + faval;
	if (fi[fa] != x) u[x] = max(u[x], f[fa] + faval);
	else u[x] = max(u[x], cf[fa] + faval);
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa)
			dfs2(v[x][i], x, w[x][i]);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
    	int x, y, z;
    	cin >> x >> y >> z;
    	v[x].push_back(y);
    	v[y].push_back(x);
    	w[x].push_back(z);
    	w[y].push_back(z);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0); 
	for (int i = 1; i <= n; i++)
		cout << max(f[i], u[i]) << '\n';
	return 0;
}
