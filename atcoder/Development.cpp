#include <iostream>
#include <algorithm>
using namespace std;

long long f[505][505];
int n, m;
void update(int w){
	for (int i = 1; i <= n+1; i++)
		for (int j = 1; j <= n+1; j++){
			f[i][j] = min(f[i][j], f[i][w] + f[w][j]);
		}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n+1; i++)
		for (int j = 1; j <= n+1; j++)
			if (i == j) f[i][j] = 0;
			else f[i][j] = 1e18;
	for (int i = 1; i <= m; i++){
		long long a, b, c;
		cin >> a >> b >> c;
		f[a][b] = f[b][a] = min(f[a][b], c);
	}
	long long k, t;
	cin >> k >> t;
	for (int i = 1; i <= k; i++){
		int d;
		cin >> d;
		f[d][n+1] = min(f[d][n+1], t);
		f[n+1][d] = 0;
	}
	for (int i = 1; i <= n+1; i++)
		update(i);
	int q;
	cin >> q;
	while (q--){
//		for (int i = 1; i <= n+1; i++){
//			for (int j = 1; j <= n+1; j++)
//				if (f[i][j] != 1e18) cout << f[i][j] << ' ';
//				else cout << "-1 "; 
//			cout << '\n';
//		}
//		cout << "-----------\n";
		int op;
		cin >> op;
		if (op == 1){
			long long x, y, c;
			cin >> x >> y >> c;
			f[x][y] = f[y][x] = min(f[x][y], c);
			update(x);
			update(y);
		} else if (op == 2){
			int x;
			cin >> x;
			f[x][n+1] = min(f[x][n+1], t); 
			f[n+1][x] = 0;
			update(x);
			update(n+1);
		} else {
			long long ans = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (f[i][j] != 1e18) ans += f[i][j];
			cout << ans << '\n';
		}
	}
	return 0;
}



