#include <iostream>
using namespace std;

int a[200005], f[200005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (f[i-1] >= 0) f[i] = f[i-1]+a[i];
		else f[i] = a[i];
		ans = max(ans, f[i]);
		cout << f[i] << ' ';
	}
	cout << ans << endl;
	return 0;
}