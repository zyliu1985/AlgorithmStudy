#include <iostream>
using namespace std;

int f[200005];
int main(){
	int n, sum = 0;
	cin >> n;
	f[1] = 1;
	f[2] = 3;
	for (int i = 3; i <= n; i++){
		if (i % 2 == 0) f[i] = f[i-1] + f[i-2] * 2 + i / 2 - 1;
		else f[i] = f[i-1] + f[i-2];
	}
	cout << f[n] << endl;
	return 0;
}