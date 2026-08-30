#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;
long long f[405][405];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		memset(f, 0, sizeof(f));
		int n, m, v;
		cin >> n >> m >> v;
		f[0][0] = 1;
		for (int i = 1; i <= n; i++){
			int a;
			cin >> a;
			for (int j = 1; j <= m; j++)
				for (int k = a; k <= v; k++)
					f[j][k] = (f[j][k] + f[j-1][k-a]) % mod;
		}
		long long ans = 0;
		for (int i = 0; i <= v; i++)
			ans = (ans + f[m][i]) % mod;
		cout << ans << '\n';
	}
	return 0;
}



