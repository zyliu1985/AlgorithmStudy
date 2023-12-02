#include <iostream>
using namespace std;

int main(){
	int n, n5, n10; // 20元纸币无法找零
	n5 = n10 = 0;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int c;
		cin >> c;
		if (c == 5){
			// 无需找零
			n5++;
			ans++;
		} else if (c == 10){
			// 只能用5元找零
			if (n5 > 0){
				n5--;
				n10++;
				ans++;
			}
		} else {
			// 可以5元+5元+5元，也可以10元+5元，优先用10元
			if (n5 > 0 && n10 > 0){
				n10--;
				n5--;
				ans++;
			} else if (n5 > 2){
				n5 -= 3;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}