#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		n++;
		string ans;
		while (n > 1){
			if (n & 1) ans = "R" + ans;
			else ans = "L" + ans;
			n >>= 1;
		}
		cout << ans << '\n';
	}
	return 0;
}



