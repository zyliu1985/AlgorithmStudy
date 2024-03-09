#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int f[100005], a[100005], t[100005];
signed main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i < n; i++){
		cin >> t[i];
		f[i] = max(f[i-1]+a[i], f[i]);
		f[t[i]] = max(f[i]+a[t[i]], f[t[i]]);
	}
	f[n] = max(f[n-1]+a[n], f[n]);
	cout << f[n] << endl;
	return 0;
}