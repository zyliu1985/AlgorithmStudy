#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

// f: 没有伐木场 
// g: 有伐木场 
int f[105][105][55], g[105][55];
int fa[105], wd[105], d[105], sd[105];
vector<int> v[105];
int cost(int x, int y){ // x -> y花费 
	return wd[x] * (sd[x] - sd[y]);
}
void dfs(int x){
	g[x][0] = 1e9;
	for (int i = 0; i < v[x].size(); i++){
		sd[v[x][i]] = sd[x] + d[v[x][i]]; // 累加距离 
		dfs(v[x][i]);
		int ch = v[x][i];
		// f
		int prd = fa[x];
		while (prd != -1){
			for (int j = 51; j >= 0; j--){
				// w = 0，min计算的第一项 
				f[x][prd][j] += f[ch][prd][0];
				for (int w = 1; w <= j; w++)
					f[x][prd][j] = min(f[x][prd][j], min(f[ch][prd][w], g[ch][w]) + f[x][prd][j-w]);
			}
			prd = fa[prd];
		}
		// g
		for (int j = 51; j >= 1; j--){
			// w = 0
			g[x][j] += f[ch][x][0];
			for (int w = 1; w < j; w++)
				g[x][j] = min(g[x][j], min(f[ch][x][w], g[ch][w]) + g[x][j-w]);
		}
	}
	// 计算x贡献 
	int prd = fa[x];
	while (prd != -1){
		for (int j = 51; j >= 0; j--)
			f[x][prd][j] += cost(x, prd);
		prd = fa[prd];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> wd[i] >> fa[i] >> d[i];
		v[fa[i]].push_back(i);
	}
	fa[0] = -1; // 终止查找祖先 
	dfs(0);
	cout << g[0][k+1] << '\n';
	return 0;
}

