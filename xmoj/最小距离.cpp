#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	cout << 2019201997 - 84 * (k-1) - 48 * n << '\n';
	return 0;
}
