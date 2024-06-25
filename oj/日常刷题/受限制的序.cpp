#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;
int b[200005];
long long ans = 1;
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	sort(b+1, b+n+1);
	for (int i = 1; i <= n; i++)
		ans = (ans * (b[i] - i + 1)) % mod;
	cout << ans << endl;
	return 0;
}