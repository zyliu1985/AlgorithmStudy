#include <iostream>
#include <algorithm>
using namespace std;

int c[25][25];
long long a[25];
int n, m;
long long y;
__int128 gcd(__int128 x, long long y){
	if (x % y == 0) return y;
	return gcd(y, x % y);
}
__int128 lcm(__int128 x, long long y){
	return x * y / gcd(x, y);
}
long long dfs(int x, int num, __int128 lm){
	if (lm > y) return 0;
	if (x > n){
		if (num < m) return 0;
		return (y / lm) * c[num][m];
	} else {
		return dfs(x+1, num, lm) - dfs(x+1, num + 1, lcm(lm, a[x]));
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> y;
	c[0][0] = 1;
	for (int i = 1; i <= n; i++){
		c[i][0] = 1, c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << abs(dfs(1, 0, 1)) << '\n';
	return 0;
}

