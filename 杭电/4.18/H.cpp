#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		cout << a * b * c * d * (d-1) / 2 + a * b * c * d * e << '\n';
	}
	return 0;
}



