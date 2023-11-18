	#include <iostream>
	#include <cmath>
	using namespace std;
	
	int main() {
		int n;
		cin >> n;
		
		
		int total = 0, d = 0;
		bool f = false;
		while (n > 0) {
			total++;
			if(!f) {
				d++;
				if(n % 3 == 1) {
					f = true;
				}
			}
			
			n = n - ceil(n / 3.0);
		}
		
		cout << total << ' ' << d << endl;
		return 0;
	}