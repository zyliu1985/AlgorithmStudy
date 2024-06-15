#include <iostream>
using namespace std;

bool f[2][5000005];
int main(){
	int t, a, b;
	cin >> t >> a >> b;
	f[0][0] = true;
	for (int i = 1; i <= t; i++){
		if (i-a >= 0)
			f[0][i] |= f[0][i-a];
		if (i-b >= 0)
			f[0][i] |= f[0][i-b];
	}
	for (int i = 1; i <= t; i++){
		if (i-a >= 0)
			f[1][i] |= f[1][i-a];
		if (i-b >= 0)
			f[1][i] |= f[1][i-b];
		if (i*2 <= t)
			f[1][i] |= f[0][i*2];
		if (i*2+1 <= t)
			f[1][i] |= f[0][i*2+1];
	}
	int cur = t;
	while (cur){
		if (f[0][cur] | f[1][cur]) break;
		cur--;
	}
//	for (int i = 1; i <= t; i++)
//		cout << f[0][i] << ' ';
//	cout << endl;
//	for (int i = 1; i <= t; i++)
//		cout << f[1][i] << ' ';
	cout << cur << endl;
	return 0;
}