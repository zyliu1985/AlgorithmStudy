#include <iostream>
#include <algorithm>
using namespace std;

const int M = 5e6+5;
int oiia = 0;
int cnt, lc[M], rc[M], val[M], lz[M];
int new_node(){
	cnt++;
	lc[cnt] = rc[cnt] = val[cnt] = lz[cnt] = 0;
	return cnt;
} 
void push_up(int x){
	val[x] = min(val[lc[x]], val[rc[x]]) + lz[x];
}
void push_down(int x){
	if (lz[x] != 0){
		if (!lc[x]) lc[x] = new_node();
		if (!rc[x]) rc[x] = new_node();
		val[lc[x]] += lz[x];
		val[rc[x]] += lz[x];
		lz[lc[x]] += lz[x];
		lz[rc[x]] += lz[x];
		lz[x] = 0;
	}
}
int n, q;
void add(int lt, int rt, int u, int l, int r, int &x){
	if (r < lt || rt < l) return;
	if (x == 0) x = new_node();
	if (lt <= l && r <= rt){
		val[x] += u;
		lz[x] += u;
		return;
	}
	push_down(x);
	add(lt, rt, u, l, (l + r) / 2, lc[x]);
	add(lt, rt, u, (l + r) / 2 + 1, r, rc[x]);
	push_up(x);
}
int quary(int lt, int rt, int l, int r, int &x){
	if (r < lt || rt < l) return 1e9;
	if (x == 0) return 0;
	if (lt <= l && r <= rt) return val[x];
	push_down(x);
	return min(quary(lt, rt, l, (l + r) / 2, lc[x]), quary(lt, rt, (l + r) / 2 + 1, r, rc[x]));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int a, b, v;
			cin >> a >> b >> v;
			add(a, b, v, 1, n, oiia);
		} else {
			int a, b;
			cin >> a >> b;
			cout << quary(a, b, 1, n, oiia) << '\n';
		}
	}
	return 0;
}

