#include <iostream>
using namespace std;

int a[3][200005], f[3][200005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[0][i] >> a[1][i] >> a[2][i];
	for (int i = 1; i <= n; i++){
		f[0][i] = max(f[1][i-1], f[2][i-1]) + a[0][i];
		f[1][i] = max(f[0][i-1], f[2][i-1]) + a[1][i];
		f[2][i] = max(f[0][i-1], f[1][i-1]) + a[2][i];
	}
	cout << max(f[0][n], max(f[1][n], f[2][n])) << endl;
	return 0;
}