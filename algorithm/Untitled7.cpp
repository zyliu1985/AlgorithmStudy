#include <iostream>
using namespace std;

int f[105][105], a[10005];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> f[i][j];
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	int ans = 0;
	for (int i = 1; i < m; i++)
		ans += f[a[i]][a[i+1]];
	cout << ans << endl;
	return 0;
}