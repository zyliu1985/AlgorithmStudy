#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		ans += x;
	}
	cout << ans << '\n';
	return 0;
}

