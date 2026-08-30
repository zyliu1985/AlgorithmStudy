#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

int n, m;
vector<int> v[100005];
int b[100005], c[100005], l[100005];
int ch[100005], nxtb[100005], top[100005];
long long sz[100005], sum[100005];
long long ans = 0;
int merge(int x, int y){
	if (x == 0) return y;
	if (y == 0) return x; 
	if (c[x] < c[y]) swap(x, y);
	nxtb[y] = ch[x];
	ch[x] = y;
	sum[x] += sum[y];
	sz[x] += sz[y];
	return x;
}
int merges(int x){
	if (nxtb[x] == 0) return x;
	int y = nxtb[x];
	int z = nxtb[y];
	nxtb[x] = nxtb[y] = 0;
	return merge(merge(x, y), merges(z));
}
int del(int x){
	int newtop = merges(ch[x]);
	ch[x] = 0;
	return newtop;
}
void dfs(int x){
	for (int i = 0; i < v[x].size(); i++){
		dfs(v[x][i]);
		top[x] = merge(top[x], top[v[x][i]]);
	}
	while (sum[top[x]] > m && sz[top[x]] > 1) top[x] = del(top[x]);
	if (sum[top[x]] <= m) ans = max(ans, sz[top[x]] * l[x]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> b[i] >> c[i] >> l[i];
		if (b[i]) v[b[i]].push_back(i);
		sum[i] = c[i];
		sz[i] = 1;
		top[i] = i;
	}
	for (int i = 1; i <= n; i++)
		if (!b[i]) dfs(i);
	cout << ans << '\n';
	return 0;
}

