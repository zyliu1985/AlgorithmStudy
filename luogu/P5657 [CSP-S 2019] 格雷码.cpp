#include <iostream>
#include <algorithm>
using namespace std;

int n;
unsigned long long rev(unsigned long long x){
	unsigned long long re = 0;
	for (int i = 1; i <= n; i++){
		re <<= 1;
		re += x & 1;
		x >>= 1;
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	unsigned long long k;
	cin >> n >> k;
	k = rev(k);
	bool inv = 0;
	while (n--){
		bool prt;
		if (k & 1){
			prt = (1 ^ inv);
		} else {
			prt = inv;
		}
		if (prt) inv ^= 1;
		cout << prt;
		k >>= 1;
	}
	return 0;
}

