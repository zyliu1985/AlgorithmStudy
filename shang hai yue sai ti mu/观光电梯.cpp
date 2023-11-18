#include <iostream>
#include <cmath>
using namespace std;

int a[100005];

int box[4];

int main() {
	int i = 1;
	while (cin >> a[i]) {
		box[a[i]]++;
		i++;
	}
	
	int ans = box[4];
	int left = 0;
	ans += box[2] / 2;
	if(box[2] % 2 == 1) {
		left = 2;
	}
	
	if(box[1] >= box[3]) {
		ans += box[3];
		int ls = box[1] - box[3];
		
		if(ls <= 2 && ls > 0) {
			ans++;
		} else {
			ans += ceil((ls - left)/4.0);
			if(left > 0) ans++;	
		}
	} else {
		ans += box[1];
		int ls = box[3] - box[1];
		
		ans += ls + (left > 0);
	}
	
	cout << ans;
	
	return 0;
}