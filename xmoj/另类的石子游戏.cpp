#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		cout << !((n - (n + m - 1) / m) & 1) << '\n';
	}
	return 0;
}

