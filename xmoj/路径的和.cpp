#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v[60005], w[60005];
long long sz[60005];
int n;
long long ans;
void dfs(int x, int fa){
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			dfs(v[x][i], x);
			sz[x] += sz[v[x][i]];
		}
}
void solve(int x, int fa){
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa){
			ans += sz[v[x][i]] * (n - sz[v[x][i]]) * w[x][i]; 
			solve(v[x][i], x);
		}
} 
void write(__int128 x){
	if (x < 10){
		putchar(x + '0');
		return;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}
int main(){
//	freopen("5.in", "r", stdin);
	ios::sync_with_stdio(0);
    cin.tie(0);
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
	solve(1, 0);
	write(ans);
	return 0;
}
