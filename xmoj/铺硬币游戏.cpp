#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	freopen("coin.in", "r", stdin);
	freopen("coin.out", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
	long long a, b;
	cin >> a >> b;
	if (a >= b) cout << "S\n";
	else cout << "K\n";
	return 0;
}



