#include <iostream>
using namespace std;

int f[2005], count[2005];
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
	for (int i = 1; i <= 2000; i++) f[i] = i;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		char z;
		int x, y;
		cin >> z >> x >> y;
		if (z == 'F'){
			merge(x, y);
			// merge(x+n, y+n);
		} else {
			merge(x+n, y);
			merge(x, y+n);
		}
	}
	for (int i = 1; i <= n; i++)
		count[find(i)]++;
	int ans = 0;
	for (int i = 1; i <= n*2; i++)
		ans += bool(count[i]);
	cout << ans << endl;
	return 0;
}