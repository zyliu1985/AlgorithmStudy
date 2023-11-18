#include <iostream>
using namespace std;

int n, f[1000005];
int main(){
	cin >> n;
	f[1] = f[5] = f[11] = 1;
	for (int i = 2; i <= n; i++){
		if (i == 5 || i == 11) continue;
		f[i] = f[i-1]+1;
		if (i > 5)
			f[i] = min(f[i], f[i-5]+1);
		if (i > 11)
			f[i] = min(f[i], f[i-11]+1);
	}
	cout << f[n] << endl;
	return 0;
}