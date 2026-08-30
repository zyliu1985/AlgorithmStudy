#include <iostream>
using namespace std;

bool a[3][200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c;
	cin >> c;
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= c; j++)
			cin >> a[i][j];
	int ans = 0;
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= c; j++)
			ans += a[i][j] * (3 - (a[i-1][j] * (j & 1) + a[i][j-1]) * 2);
	cout << ans << '\n';
	return 0;
}
