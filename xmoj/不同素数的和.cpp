#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool ishe[20005];
int p[2300], f[2300][20005], cur;
int main(){
	freopen("prime.in", "r", stdin);
	freopen("prime.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(f, -0x3f, sizeof(f));
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
		if (!ishe[i]){
			p[++cur] = i;
			for (int j = i + i; j <= n; j += i)
				ishe[j] = true;
		}
//	for (int i = 1; i <= cur; i++)
//		cout << p[i] << ' ';
	f[0][0] = 0;
	for (int i = 1; i <= cur; i++)
		for (int j = 0; j <= n; j++){
			f[i][j] = max(f[i-1][j], j >= p[i] ? (f[i-1][j-p[i]] + 1) : -1000000000);
		}
	if (f[cur][n] < 0) cout << -1 << '\n';
	else cout << f[cur][n] << '\n';
	return 0;
}

