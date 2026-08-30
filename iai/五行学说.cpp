#include <iostream>
#include <algorithm>
using namespace std;

int f[100005], d[100005];
int norm(int x){
	x %= 5;
	x += 5;
	x %= 5;
	return x;
}
int find(int x){
	if (f[x] == x) return x;
	find(f[x]);
	d[x] = norm(d[x] + d[f[x]]);
	f[x] = f[f[x]];
	return f[x];
}
bool merge(int x, int y, int k){
	int zx = find(x);
	int zy = find(y);
	// y = x + k;
	if (zx == zy){
//		cout << "**:" <<d[y] <<' ' << norm(d[x] + k) <<'\n';
		return (d[x] == norm(d[y] + k));
	}
	f[zx] = y;
	d[zx] = norm(k - d[x]);
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	while (m--){
		char c;
		int x, y;
		cin >> c >> x >> y;
		int add = (c == 's') ? 1 : 2;
		ans += (!merge(x, y, add));
//		for (int i = 1; i <= n; i++)
//			cout << f[i] << ' ' << d[i] << '\n';
//		cout << '\n';
	}
	cout << ans << '\n';
	return 0;
}

