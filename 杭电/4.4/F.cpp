#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int d, r, x, y;
		cin >> d >> r >> x >> y;
		x = abs(x);
		y = abs(y);
		if (abs(y) > d){
			y -= d;
			cout << round(abs(sqrt(x * x + y * y) - r)) << '\n';
		} else {
			cout << abs(r - x) << '\n';
		}
	}
	return 0;
}
