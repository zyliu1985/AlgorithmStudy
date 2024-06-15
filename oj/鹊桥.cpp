#include <iostream>
#include <vector>
using namespace std;

int f[100005], d[100005];
vector<int> v[100005];
void dfs(int x){
	cout << x << endl;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != f[x]){
			f[v[x][i]] = x;
			d[v[x][i]] = d[x]+1;
			dfs(v[x][i]);
		}
}
int main(){
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 1; i <= q; i++){
		int st, ed;
		cin >> st >> ed;
		int t = d[st]+d[ed];
		if (t & 1) cout << 'Y' << endl;
		else cout << 'N' << endl;
	}
	return 0;
}