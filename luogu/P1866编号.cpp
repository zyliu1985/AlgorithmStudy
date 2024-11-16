#include <iostream>
#include <algorithm>
using namespace std;

int m[55];
const int mod = 1000000007;
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> m[i];
	sort(m+1, m+n+1);
	int x = 0;
	long long ans = 1;
	for (int i = 1; i <= n; i++)
		if (m[i] - x < 1){
			cout << 0 << endl;
			return 0;
		} else {
			ans *= m[i] - x;
			ans %= mod;
			x++;
		}
	cout << ans << endl;
	return 0;
}