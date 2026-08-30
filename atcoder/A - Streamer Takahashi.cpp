#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, l, r;
	cin >> n >> l >> r;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		if (x <= l && r <= y)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}



