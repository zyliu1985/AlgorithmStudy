#include <iostream>
using namespace std;

int f[2][105];
int main(){
	int n, k, d;
	cin >> n >> k >> d;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k && j <= i; j++){
			f[0][i] += f[0][i-j];
			f[1][i] += f[1][i-j];
			if (j >= d) f[1][i] += f[0][i-j];
		}
	cout << f[n][1] << endl;
	return 0;
}