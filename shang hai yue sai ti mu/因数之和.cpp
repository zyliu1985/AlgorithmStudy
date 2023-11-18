#include <iostream>
using namespace std;

int box[1000005];

bool zhishu(int n) {
	for(int i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

long long sumYinshu(int n) {
	long long ans = 0;
	for(int i = 1; i * i <= n; i++) {
		if(i * i == n) ans += i;
		else if(n % i == 0) {
			if(box[i] > 0 && i > 1) {
				ans = box[i] + n;
				break;
			} else {
				ans += i;
				ans += n / i;
			}
		}
	}
	box[n] = ans;
	
	return ans;
}

int main(){
	int n;
	cin >> n;
	
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += sumYinshu(i);
	}
	
	cout << ans << endl;
	
	return 0;
}