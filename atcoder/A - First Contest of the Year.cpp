#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int d, f;
//	cin >> d >> f;
//	
//	int a =  (f - (d%7) + 7) % 7;
//	int b = 7 - (d - f) % 7;
//	cout << (f - (d%7) + 7) % 7 << '\n';
//	cout << (f + (7 * (d/7) - d)) % 7 << '\n'; 
//	cout << 7 - (d - f) % 7 << '\n'; 

	for (int i = 10; i <= 366; i++) {
		for(int j = 1; j <= 7; j++) {
			int a =  (((f - (d%7) + 7) % 7) + 6) % 7 + 1;
			int b = 7 - (d - f) % 7;
			if(a != b)
				cout << a << ' ' << b << endl;
		}
	}
	return 0;
}

