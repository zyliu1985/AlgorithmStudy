#include <iostream>
using namespace std;

int f[100005];
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
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++){
		int x;
		cin >> x;
		if (find(x) == 0){
			cout << i-1 << '\n';
			return 0;
		} else merge(find(x), find(x)-1);
	}
	cout << m << '\n';
	return 0;
}
