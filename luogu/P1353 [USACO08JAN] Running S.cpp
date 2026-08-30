#include <iostream>
#include <algorithm>
using namespace std;

long long f[10005][505];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int d;
		cin >> d;
		for (int j = 0; j <= m; j++){
			if (j > 0) f[i][j] = max(f[i-1][j-1] + d, f[i-1][j+1]);
			else f[i][j] = max(f[i-1][j], f[i-1][j+1]);
			cout << f[i][j] << ' '; 
		}
		cout << '\n';
	}
	cout << f[n][0] << '\n';
	return 0;
}

