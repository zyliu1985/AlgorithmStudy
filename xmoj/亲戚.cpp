#include <iostream>
#include <algorithm>
using namespace std;

int f[20005]; 
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
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	int q;
	cin >> q;
	while (q--){
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}

