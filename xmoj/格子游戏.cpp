#include <iostream>
#include <algorithm>
using namespace std;

bool vis[205][205][2];
int f[40005]; 
int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
bool merge(int x, int y){
	int zx = find(x), zy = find(y);
	if (zx != zy){
		f[zx] = zy;
		return false;
	} else {
		return true;
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++){
		int a, b;
		char c;
		cin >> a >> b >> c;
		if (c == 'D'){
			if (vis[a][b][0]) continue;
			else vis[a][b][0] = true;
			if (merge((a - 1) * n + b, a * n + b)){
				cout << i << '\n';
				return 0;
			}
		} else {
			if (vis[a][b][1]) continue;
			else vis[a][b][1] = true;
			if (merge((a - 1) * n + b, (a - 1) * n + b + 1)){
				cout << i << '\n';
				return 0;
			}
		}
	}
	cout << "draw\n";
	return 0;
}

