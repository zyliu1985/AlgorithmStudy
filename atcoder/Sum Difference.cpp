#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, st, d;
	cin >> n >> st >> d;
	if (d == 0){
		if (st == 0) cout << 1 << '\n';
		else cout << n+1 << '\n';
	} else if (d < 0){
		d = -d;
		st = -st;
	}
	for (int i = 1; i <= n; i++){
		
	}
	return 0;
}

