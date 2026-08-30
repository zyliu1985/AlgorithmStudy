#include <iostream>
#include <algorithm>
using namespace std;

int a[300005], b[300005], c[300005];
long long f[300005][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	f[1][0] = a[1];
	f[1][1] = f[1][2] = -1e18;
	for (int i = 2; i <= n; i++){
		f[i][0] = f[i-1][0] + a[i];
		f[i][1] = max(f[i-1][0], f[i-1][1]) + b[i];
		f[i][2] = max(f[i-1][1], f[i-1][2]) + c[i];
	}
	cout << f[n][2] << '\n';
	return 0;
}

