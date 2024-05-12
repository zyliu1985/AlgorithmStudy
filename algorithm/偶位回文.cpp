#include <iostream>
#include <cmath>
using namespace std;

int len(int x){
	if (x == 0) return 1;
	int re = 0;
	while (x > 0){
	    x /= 10;
	    re++;
	}
	return re;
}
int dao(int x){
	int re = 0;
	while (x > 0){
		int s = x % 10;
		x /= 10;
		re = re * 10 + s;
	}
	return re;
}
int main() {
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		long long now = i * pow(10, len(i)) + dao(i);
		ans += now;
	}
	cout << ans << endl;
	return 0;
}