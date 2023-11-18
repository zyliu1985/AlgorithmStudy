#include <iostream>
#include <algorithm>
using namespace std;

int a[300005];
int main(){
	int n;
	cin >> n;
	long long ans = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){
		ans *= a[i]-i+1;
		ans %= 1000000007;
	}
	cout << ans << endl;
	return 0;
}