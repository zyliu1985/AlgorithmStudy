#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[405];
long long f[2][25][305];
int main(){
	freopen("stock.in", "r", stdin);
	freopen("stock.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n+1; i++)
		cin >> a[i];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j <= 20; j++)
			for (int l = 0; l <= 300; l++)
				f[i][j][l] = -1e15;
	f[0][0][0] = k;
	bool now = 1;
	for (int i = 1; i <= n+1; i++){
		for (int j = 0; j <= m; j++)
			for (int l = 0; l <= 300; l++){
				f[now][j][l] = f[now^1][j][l]; // 啥也不做 
				if (l == a[i]) f[now][j][l] = max(f[now][j][l], f[now^1][j][0]); // 买入股票
				if (l == 0 && j != 0){
					for (int r = 1; r <= 300; r++)
						f[now][j][l] = max(f[now][j][l], f[now^1][j-1][r] + f[now^1][j-1][r] / r * (a[i] - r));
					// 卖出股票 
				}
			}
		now ^= 1;
	}
	now ^= 1;
	long long ans = 0;
	for (int j = 0; j <= m; j++){
		ans = max(ans, f[now][j][0]);
	}
	cout << ans << '\n';
	return 0;
}

