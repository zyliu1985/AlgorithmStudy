#include <iostream>
#include <cstring>
using namespace std;

int f[10000005];
int main(){
	int s, t;
	cin >> s >> t;
	memset(f, 0x3f, sizeof(f));
	f[s] = 0;
	for (int i = s+1; i <= t; i++){
		f[i] = f[i-1]+1;
		if (i % 2 == 0) f[i] = min(f[i], f[i/2]+1);
	}
	cout << f[t] << endl;
	return 0;
}