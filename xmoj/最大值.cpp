#include <iostream>
#include <algorithm>
using namespace std;

int n;
int Log2[100005];
int f[25][100005];
void init(){
	Log2[0] = -1;
	for (int i = 1; i <= 100000; i++)
		Log2[i] = Log2[i / 2] + 1;
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= n - (1 << i) + 1; j++)
			f[i][j] = max(f[i-1][j], f[i-1][j + (1 << (i-1))]);
}
int quary(int l, int r){
	int k = Log2[r - l + 1];
	return max(f[k][l], f[k][r - (1 << k) + 1]);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> f[0][i];
	init();
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		cout << quary(x, y) << '\n';
	}
	return 0;
}



