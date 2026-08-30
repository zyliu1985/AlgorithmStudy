#include <iostream>
#include <algorithm>
using namespace std;

int ctp[1000005], ptc[1000005], mtc[1000005];
int f[1000005];
int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y){
	int zx = find(x), zy = find(y);
	if (zx != zy){
		f[zx] = zy;
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++)
			f[i] = i;
		for (int i = 1; i <= n; i++)
			ctp[i] = ptc[i] = mtc[i] = i;
		while (q--){
			int op;
			cin >> op;
			if (op == 1){
				int a, b;
				cin >> a >> b;
				merge(ptc[b], ptc[a]);
			} else if (op == 2){
				int a, b;
				cin >> a >> b;
				mtc[a] = ptc[b]; 
			} else if (op == 3){
				int a, b;
				cin >> a >> b;
				swap(ctp[ptc[a]], ctp[ptc[b]]);
				swap(ptc[a], ptc[b]);
			} else {
				int a;
				cin >> a;
				cout << ctp[find(mtc[a])] << '\n';
			}
		}
	} 
	return 0;
}



