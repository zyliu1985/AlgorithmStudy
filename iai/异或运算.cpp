#include <iostream>
#include <algorithm>
using namespace std;

int a, b, l, r;
long long calc(int x){
	return (a + b + (a^b)) * 1ll * (x / 3) + ((x % 3 == 1) ? a : ((x % 3 == 2) ? (a + b) : 0));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> a >> b >> l >> r;
		cout << calc(r) - calc(l-1) << '\n';
	} 
	return 0;
}

