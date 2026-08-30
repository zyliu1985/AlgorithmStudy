#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[505];
long long f[505][505], cst[505][505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, l;
	cin >> n >> m >> l; 
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= l; i++)
		for (int j = i; j <= n; j += l)
			for (int k = 0; k < m; k++)
				cst[i][k] += (k + m - a[j]) % m;
//	for (int i = 1; i <= l; i++){
//		for (int j = 0;  j < m; j++)
//			cout << cst[i][j] << ' ';
//		cout << '\n';
//	}
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++)
				f[i][j] = min(f[i][j], f[i-1][(j + m - k) % m] + cst[i][k]);
	cout << f[l][0] << '\n';
	return 0;
}

