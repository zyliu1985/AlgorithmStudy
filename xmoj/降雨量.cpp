#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int y[50005], magic[50005];
int n;
int Log2[50005];
int f[20][50005];
map<int, int> mp;
void init(){
	Log2[0] = -1;
	for (int i = 1; i <= 50000; i++)
		Log2[i] = Log2[i / 2] + 1;
	for (int i = 1; i <= 18; i++)
		for (int j = 1; j <= n - (1 << i) + 1; j++)
			f[i][j] = max(f[i-1][j], f[i-1][j + (1 << (i-1))]);
}
int quary(int l, int r){
	if (l > r) return -1e9;
	int k = Log2[r - l + 1];
	return max(f[k][l], f[k][r - (1 << k) + 1]);
}
int main(){
//	freopen("1.in", "r", stdin);
//	freopen("1.outt", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> y[i] >> f[0][i];
		mp[y[i]] = f[0][i];
	}
	for (int i = 1; i <= n; i++)
		magic[i] = y[i] == y[i-1] + 1 ? magic[i-1] : i;
	init();
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		int ll = lower_bound(y+1, y+n+1, u) - y;
		int rr = upper_bound(y+1, y+n+1, v) - y - 1; 
		u++;
		v--;
		int l = lower_bound(y+1, y+n+1, u) - y;
		int r = upper_bound(y+1, y+n+1, v) - y - 1;
//		cout << quary(l, r) << ' ' << quary(l, r - 1) << '\n'; 
//		if (y[r] != v){
//			cout << "maybe\n";
//		} else if (quary(l, r) == f[0][r] && quary(l, r - 1) != quary(l, r) && f[0][r] <= f[0][newl]){
//			if (y[newl] != u - 1 || magic[r] > newl) cout << "maybe\n";
//			else cout << "true\n";
//		} else {
//			cout << "false\n";
//		}
		int mid = quary(l, r);
		if (y[ll] != u-1 && y[rr] != v+1){
			cout << "maybe\n";
		} else if (y[ll] != u-1){
			if (mid < mp[v+1]) cout << "maybe\n";
			else cout << "false\n";
		} else if (y[rr] != v+1){
			if (mid < mp[u-1]) cout << "maybe\n";
			else cout << "false\n";
		} else {
//			cout << mp[v+1] << ' ' << mp[u-1] << ' ' << quary(l, r) << '\n';
			if (quary(l, r) < mp[v+1] && mp[v+1] <= mp[u-1]){
				if (magic[rr] > ll) cout << "maybe\n";
				else cout << "true\n";
			} else {
				cout << "false\n";
			}
		}
//		cout << "---" << l << ' ' << r << ' ' << newl << ' ';
//		cout << u << ' ' << v << '\n';
	}
	return 0;
}



