#include <iostream>
using namespace std;

int f[5005], size[5005];
int find_rt(int x){
	int root = x;
	while (f[root] != 0){
		root = f[root];
	}
	while (f[x] != 0){
		int nxt = f[x];
		f[x] = root;
		x = nxt;
	}
	return root;
}
void he(int x, int y){
	int art, brt;
	art = find_rt(x);
	brt = find_rt(y);
	if (art == brt) return;
	if (size[art] > size[brt]){
		f[brt] = art;
		size[art] += size[brt];
	} else {
		f[art] = brt;
		size[brt] += size[art];
	}
}
int main(){
	for (int i = 1; i <= 5000; i++) size[i] = 1;
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		he(x, y);
	}
	for (int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		if (find_rt(x) == find_rt(y))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}