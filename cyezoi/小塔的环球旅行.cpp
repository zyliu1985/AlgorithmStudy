#include <iostream>
#include <algorithm>
using namespace std;

int main(){
//	ios::sync_with_stdio(0);
//    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		while (n--){
			int x, y, d, f = 1;
			char a, b;
			cin >> a >> b;
			x = (a - '0') * 10 + (b - '0');
			cin >> a;
			cin >> a >> b;
			y = (a - '0') * 10 + (b - '0');
			cin >> a;
			if (a == '-') f = -1;
			cin >> d;
			d *= f;
			x = (x + d + 24) % 24;
			if (x < 10) cout << 0;
			cout << x << ':';
			if (y < 10) cout <<0;
			cout << y << '\n';
		}
	}
	return 0;
}



