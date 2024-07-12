#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct node{
	int val, id;
};
int n, m;
bool vis[5005], cir[5005], empty; // empty：由于minans初始值都是0，所以在第一次solve函数的时候要直接更新
int dfn[5005], low[5005], clk; // dfn，low：tarjan两件套（bushi）
bool cut[5005]; // 桥标记
vector<node> v[5005];
int cnt = -1, ans[5005], minans[5005], cur, flag = -1; // cnt：拆边标记，flag：有返祖边的点
bool sort_cmp(node x, node y){
	return x.val < y.val;
}
void tarjan(int x, int ide){ // tarjan求桥
	dfn[x] = low[x] = ++clk;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i].id == ide) continue;
		if (dfn[v[x][i].val] == 0){
			tarjan(v[x][i].val, v[x][i].id);
			low[x] = min(low[x], low[v[x][i].val]);
			if (dfn[x] < low[v[x][i].val]) cut[v[x][i].id] = true;
		} else low[x] = min(low[x], dfn[v[x][i].val]);
	}
}
void solve(int x, int fa){
	if (vis[x])
		return;
	vis[x] = true;
	ans[++cur] = x;
	for (int i = 0; i < v[x].size(); i++){
		int y = v[x][i].val;
		if(y == fa)
			continue;
		if(v[x][i].id == cnt)
			continue;
		solve(y, x);
	}
}
void update(){ // 比较并更新
	if (empty){
		for (int i = 1; i <= n; i++)
			minans[i] = ans[i];
		empty = false;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (ans[i] < minans[i]){
			for (int j = i; j <= n; j++)
				minans[j] = ans[j];
			return;
		} else if (ans[i] > minans[i])
			return;
	}
	return;
} 
int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back({y, i});
		v[y].push_back({x, i});
	}
	for (int i = 1; i <= n; i++) // Tips：作者之前就是这里写了m，导致一直是96分qwq，大家可别跟我犯一样的错误哟
		sort(v[i].begin(), v[i].end(), sort_cmp);
	tarjan(1, 0);
	if (m == n-1){
		solve(1, 0);
		for (int i = 1; i <= n; i++)
			cout << ans[i] << ' ';
		cout << endl;
	} else {
		empty = true;
		for (int i = 1; i <= m; i++){
			if (cut[i]) continue; // 如果是桥就跳过
			memset(vis, false, sizeof(vis));
			cur = 0;
			cnt = i;
			solve(1, 0);
			if (cur == n)
				update();
		}
		for (int i = 1; i <= n; i++)
			cout << minans[i] << ' ';
		cout << endl;
	}
	return 0;
}