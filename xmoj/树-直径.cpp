#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[60005], w[60005];
int val[60005]
void dfs(int x, int fa){
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			val[v[x][i]] = val[x] + w[x][i];
			dfs(v[x][i], x);
		}
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
	dfs(1, 0);
	int a = 1;
	for (int i = 2; i <= n; i++){
		if (val[i] > val[a]) a = i;
	val[a] = 0;
	dfs(a, 0);
	int b = 1;
	for (int i = 2; i <= n; i++)
		if (val[i] > val[b]) b = i;
	cout << val[b] << '\n';
	return 0;
}
