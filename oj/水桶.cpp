#include <iostream>
#include <cmath>
using namespace std;

bool f[105][105][105];
int main(){
	int a, b, k, m;
	cin >> a >> b >> k >> m;
	f[0][0][0] = true;
	for (int i = 0; i <= k; i++)
		for (int x = 0; x <= a; x++)
			for (int y = 0; y <= b; y++){
				if (!f[x][y][i]) continue;
				// 第一种操作
				f[0][y][i+1] = true;
				f[x][0][i+1] = true;
				// 第二种操作
				f[a][y][i+1] = true;
				f[x][b][i+1] = true;
				// 第三种操作
				if (x <= b - y) // 倒空
					f[0][y + x][i+1] = true;
				else // 倒一部分
					f[x - b + y][b][i+1] = true;
				// 下面同理
				if (y <= a - x)
					f[x + y][0][i+1] = true;
				else
					f[a][y - a + x][i+1] = true;
			}
	int ans = 1e9;
	for (int i = 0; i <= k; i++)
		for (int x = 0; x <= a; x++)
			for (int y = 0; y <= b; y++)
				if (f[x][y][i])
					ans = min(ans, abs(x + y - m));
	cout << ans << endl;
	return 0;
}