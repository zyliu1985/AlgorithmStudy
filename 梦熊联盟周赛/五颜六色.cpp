#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
int f[500005], child[500005], depth[500005];
int n, k;
vector<int> v[500005];
void dfs(int x, int fa, int numch){
	f[x] = k;
	if (depth[x] > 2) f[x] -= 2;
	else if (depth[x] > 1) f[x]--;
	if (fa != 0) f[x] -= numch;
	if (fa != 0) child[x] = v[x].size() - 1;
	else child[x] = v[x].size();
	int cur = 0;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] == fa) continue;
		else{
			depth[v[x][i]] = depth[x] + 1;
			dfs(v[x][i], x, cur++);
		}
}
int main(){
	cin >> n >> k;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	depth[1] = 1;
	dfs(1, 0, 0);
	long long ans = 1;
	for (int i = 1; i <= n; i++){
		if (f[i] <= 0){
			cout << 0 << endl;
			return 0;
		}
		ans *= f[i];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}