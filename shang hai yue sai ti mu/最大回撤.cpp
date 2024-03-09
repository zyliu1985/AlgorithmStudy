#include <iostream>
#include <cmath>
using namespace std;

int a[100005], f[100005];
int main(){
	int n;
	cin >> n;
	f[1] = -1e9;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (i > 1) f[i] = max(f[i-1], a[i-1]);
	}
	int ans = -1e9;
	for (int i = 2; i <= n; i++){
		ans = max(ans, f[i] - a[i]);
	}
	cout << max(0, ans) << endl;
	return 0;
}