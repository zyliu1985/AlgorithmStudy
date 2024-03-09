#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int f[1005], D[4] = {0, 6, 8, 12};
int a[4];
int main(){
	int n;
	cin >> n >> a[1] >> a[2] >> a[3];
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= 3; i++){
		for (int j = D[i]; j <= 1000; j++){
			f[j] = min(f[j], f[j-D[i]] + a[i]);
		}
	}
//	cout << f[n] << endl;
	int ans = 1e9;
	for (int i = n; i <= 1000; i++){
		ans = min(ans, f[i]);
//		cout << ans << ' ';
	}
//	cout << endl;
	cout << ans << endl;
	return 0;
}