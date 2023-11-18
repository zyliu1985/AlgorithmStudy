#include <iostream>
using namespace std;

int n, f[5005];
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) f[i] = 1e9;
	f[3] = f[5] = 1;
	for (int i = 1; i <= n; i++){
		if (i > 3)
			f[i] = min(f[i], f[i-3]+1);
		if (i > 5)
			f[i] = min(f[i], f[i-5]+1);
	}
	if (f[n] < 1e9) cout << f[n] << endl;
	else cout << -1 << endl;
	return 0;
}