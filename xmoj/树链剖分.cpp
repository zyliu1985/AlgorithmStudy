#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, p;
int w[100005], fa[100005], sz[100005], son[100005], top[100005], id[100005], idmax[100005], dep[100005], cnt;
int tr[4 * 100005], lz[4 * 100005];
vector<int> v[100005];
void dfs1(int x, int f, int d){
	fa[x] = f;
	sz[x] = 1;
	dep[x] = d;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == f) continue;
		dfs1(v[x][i], x, d+1);
		sz[x] += sz[v[x][i]];
		if (sz[son[x]] < sz[v[x][i]])
			son[x] = v[x][i];
	}
}
void dfs2(int x, int tp){
	top[x] = tp;
	id[x] = idmax[x] = ++cnt;
	if (!son[x]) return;
	dfs2(son[x], tp);
	idmax[x] = max(idmax[x], idmax[son[x]]);
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa[x] || v[x][i] == son[x]) continue;
		dfs2(v[x][i], v[x][i]);
		idmax[x] = max(idmax[x], idmax[v[x][i]]);
	}
}
void push_up(int x, int l, int r){
	tr[x] = ((tr[x * 2] + tr[x * 2 + 1]) % p + (r - l + 1) * lz[x] % p) % p;
}
void push_down(int x, int l, int r){
	if (lz[x]){
		int k = r - l + 1;
		tr[x * 2] = (tr[x * 2] + (k / 2) * lz[x] % p) % p;
		tr[x * 2 + 1] = (tr[x * 2 + 1] + ((k + 1) / 2) * lz[x] % p) % p;
		lz[x * 2] = (lz[x * 2] + lz[x]) % p;
		lz[x * 2 + 1] = (lz[x * 2 + 1] + lz[x]) % p;
		lz[x] = 0;
	}
}
void build(int x = 1, int l = 1, int r = n){
	if (l == r){
		tr[x] = w[l];
		return;
	}
	build(x * 2, l, (l + r) / 2);
	build(x * 2 + 1, (l + r) / 2 + 1, r);
	push_up(x, l, r);
}
void add(int lt, int rt, int d, int x = 1, int l = 1, int r = n){
	if (r < lt || rt < l) return;
	if (lt <= l && r <= rt){
		tr[x] += (r - l + 1) * d;
		lz[x] += d;
		return;
	}
	push_down(x, l, r);
	add(lt, rt, d, x * 2, l, (l + r) / 2);
	add(lt, rt, d, x * 2 + 1, (l + r) / 2 + 1, r);
	push_up(x, l, r);
}
int query(int lt, int rt, int x = 1, int l = 1, int r = n){
	if (r < lt || rt < l) return 0;
	if (lt <= l && r <= rt) return tr[x];
	push_down(x, l, r);
	return (query(lt, rt, x * 2, l, (l + r) / 2) + query(lt, rt, x * 2 + 1, (l + r) / 2 + 1, r)) % p;
}
void add_line(int x, int y, int d){
	while (top[x] != top[y]){
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		add(id[top[x]], id[x], d);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	add(id[x], id[y], d);
}
void add_tree(int x, int d){
	add(id[x], idmax[x], d);
}
int query_line(int x, int y){
	int re = 0;
	while (top[x] != top[y]){
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		re = (re + query(id[top[x]], id[x])) % p;
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	re = (re + query(id[x], id[y])) % p;
	return re;
}
int query_tree(int x){
	return query(id[x], idmax[x]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int m, r;
	cin >> n >> m >> r >> p;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(r, 0, 1);
	dfs2(r, r);
	build();
	cout << id[r] << ' ' << idmax[r] << '\n';
	cout << query_tree(r) << '\n'; 
	while (m--){
		int op;
		cin >> op;
		switch (op){
			case 1:{
				int x, y, z;
				cin >> x >> y >> z;
				add_line(x, y, z);
				break;
			}
			case 2:{
				int x, y;
				cin >> x >> y;
				cout << query_line(x, y) << '\n';
				break;
			}
			case 3:{
				int x, z;
				cin >> x >> z;
				add_tree(x, z);
				break;
			}
			case 4:{
				int x;
				cin >> x;
				cout << query_tree(x) << '\n';
				break;
			}
		}
	}
	return 0;
}

