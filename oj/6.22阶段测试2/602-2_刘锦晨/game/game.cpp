#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 998244353;
int mp[505][505], f[505][505][25];
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> mp[i][j];
	f[1][1][mp[1][1] % k] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int l = 0; l < k; l++){
				f[i+1][j][l * mp[i+1][j] % k] += f[i][j][l];
				f[i][j+1][l * mp[i][j+1] % k] += f[i][j][l];
			}
//	for (int i = 0; i < k; i++){
//		cout << i << ":\n";
//		for (int x = 1; x <= n; x++){
//			for (int y = 1; y <= n; y++)
//				cout << f[x][y][i] << ' ';
//			cout << endl;
//		}
//	}
	cout << f[n][n][0] << endl;
	return 0;
}
