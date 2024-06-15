#include <iostream>
#include <cmath>
using namespace std;

long long a, b;
bool check(int mid){
	int x = a / mid + (a % mid > 0);
	int y = b / mid;
	if (x == y) return false;
	else return true;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> a >> b;
		bool flag = true;
		for (int i = 2; i <= sqrt(b); i++){
			int t = b / i;
			if (check(t)){
				cout << t << endl;
				flag = false;
				break;
			}
		}
		if (flag) cout << 0 << endl;
	}
	return 0;
}