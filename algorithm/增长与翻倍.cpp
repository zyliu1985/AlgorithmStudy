#include <iostream>
#include <cstring>
using namespace std;

int f[10000005];
int main() {
	int s, t;
	cin >> s >> t;
	
	int t1 = t;
	int ans = 0;
	while (s < t1) {
		ans++;
		if(t1 % 2 == 0 && s <= t1 / 2) t1 = t1 / 2;
		else t1 = t1 - 1;
//		cout << t1 << ' ';
	}
//	cout << endl;
	
	cout << ans << endl;
	
//	memset(f, 0x3f, sizeof(f));
//	f[s] = 0;
//	for (int i = s+1; i <= t; i++){
//		f[i] = f[i-1]+1;
//		if (i % 2 == 0) f[i] = min(f[i], f[i/2]+1);
//	}
//	cout << f[t] << endl;
	return 0;
}