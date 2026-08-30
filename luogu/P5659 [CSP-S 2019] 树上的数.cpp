#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int id[2005];
vector<int> v[2005];
vector<bool> in[2005], out[2005];
struct bcj{
	int fa[2005];
	int s[2005];
	int sz;
	void reset(){
		for (int i = 0; i < sz; i++)
			fa[i] = i, s[i] = 1;
	}
	int find(int x){
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	int size(int x){
		return s[find(x)];
	}
	bool same(int x, int y){
		return (find(x) == find(y));
	}
	void merge(int x, int y){
		int zx = find(x), zy = find(y);
		if (zx != zy){
			fa[zx] = zy;
			s[zy] += s[zx];
		}
	}
} st[2005];
int findpath(int x, int lst){ // 找到合法的编号最小节点 
	int re = 1e9;
	if (lst == 0){ // 起飞点 
		// 起飞点不可能起飞过
		for (int i = 1; i <= v[x].size(); i++){
			int u = v[x][i-1];
			if (in[x][i] || (st[x].same(0, i) && st[x].size(0) < st[x].sz)) // i被别人占用或者形成环且环的大小不够 
				continue;
			re = min(re, findpath(u, x));
		}
	} else {
		int lstid;
		// 找到过来点的边
		for (int i = 1; i <= v[x].size(); i++)
			if (v[x][i-1] == lst){
				lstid = i;
				break;
			}
		// 停止点
		if (in[x][0] || (st[x].same(lstid, 0) && st[x].size(0) < st[x].sz)){
			// 不能停止 
		} else {
			re = x;
		}
		
		// 中转点
		for (int i = 1; i <= v[x].size(); i++){
			int u = v[x][i-1];
			if (u == lst) continue;
			if (in[x][i] || (st[x].same(lstid, i) && st[x].size(i) < st[x].sz))
				continue;
			re = min(re, findpath(u, x));
		}
	}
	return re;
}
void point(int x, int a, int b){ // a -> b
	st[x].merge(a, b);
	out[x][a] = 1;
	in[x][b] = 1;
} 
bool mark(int x, int lst, int target){ // 标记路径上需要经过的点 
	// 返回值代表当前是否到达了target 
	if (lst == 0){ // 起飞点 
		for (int i = 1; i <= v[x].size(); i++){
			int u = v[x][i-1];
			if (in[x][i] || (st[x].same(0, i) && st[x].size(0) < st[x].sz)) // i被别人占用或者形成环且环的大小不够 
				continue;
			if (mark(u, x, target)){ // 找到了 
				point(x, 0, i);
				return 1;
			} 
		}
	}
	
	int lstid;
	// 找到过来点的边
	for (int i = 1; i <= v[x].size(); i++)
		if (v[x][i-1] == lst){
			lstid = i;
			break;
		}
	if (x == target){ // 找到了 
		point(x, lstid, 0);
		return 1;
	}
	
	// 中转点
	for (int i = 1; i <= v[x].size(); i++){
		int u = v[x][i-1];
		if (u == lst) continue;
		if (in[x][i] || (st[x].same(lstid, i) && st[x].size(i) < st[x].sz))
			continue;
		if (mark(u, x, target)){ // 找到了 
			point(x, lstid, i);
			return 1;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		if (n == 1){
			cout << 1 << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++)
			v[i].clear(), in[i].clear(), out[i].clear();
		for (int i = 1; i <= n; i++)
			cin >> id[i];
		for (int i = 1; i < n; i++){
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= n; i++){
			in[i].resize(v[i].size()+1);
			out[i].resize(v[i].size()+1);
			st[i].sz = v[i].size()+1;
			st[i].reset();
		}
		for (int i = 1; i <= n; i++){
			int target = findpath(id[i], 0);
			cout << target << ' ';
			mark(id[i], 0, target);
		}
		cout << '\n';
	} 
	return 0;
}

