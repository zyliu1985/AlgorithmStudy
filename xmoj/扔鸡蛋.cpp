#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	while (m > 1 && n > 1){
		n--;
		m /= 2;
		ans++;
	}
	cout << ans + m - 1 << '\n';
	return 0;
}

