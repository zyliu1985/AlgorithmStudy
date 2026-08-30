#include <iostream>
#include <algorithm>
using namespace std;

int f[200005];
bool col[200005];
int ans[200005];
int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void upd(int x){
	if (col[x] == 0){
		ans[find(x)]++;
	} else {
		ans[find(x)]--;
	}
	col[x] ^= 1;
}
void merge(int x, int y){
	int zx = find(x), zy = find(y);
	if (zx != zy){
		f[zx] = zy;
		ans[zy] += ans[zx];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int u, v;
			cin >> u >> v;
			merge(u, v);
		} else if (op == 2){
			int x;
			cin >> x;
			upd(x);
		} else {
			int x;
			cin >> x;
			if (ans[find(x)]) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}

