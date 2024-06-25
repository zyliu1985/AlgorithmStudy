#include <iostream>
using namespace std;

int f[1000005];
int find(int x){
	if (f[x] == x) return x;
	int y = find(f[x]);
	f[x] = y;
	return y;
}
void merge(int x, int y){
	int zx = find(x);
	int zy = find(y);
	if (zx != zy)
		f[zx] = zy;
}
int main(){
//    freopen("gnum.in","r",stdin);
//    freopen("gnum.out","w",stdout);
	int t;
	cin >> t;
	while (t--){
		int n, k, x, y;
		cin >> n >> k >> x >> y;
		for (int i = 1; i <= 1000000; i++) f[i] = i;
		for (int i = k+1; i <= n; i++)
			for (int j = i*2; j <= n; j += i)
				merge(i, j);
		if (find(x) == find(y)) cout << "Possible" << endl;
		else cout << "Impossible" << endl;
	}
	return 0;
}