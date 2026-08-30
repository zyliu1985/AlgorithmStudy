#include <iostream>
#include <algorithm>
using namespace std;

int mglen(int l1, int r1, int l2, int r2){
	return max(0, min(r1, r2) - max(l1, l2) + 1); 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int lx, rx, ly, ry;
	cin >> lx >> rx >> ly >> ry;
	long long ans = 0;
	for (int i = lx; i <= rx; i++){
		if (!(i & 1)){
			int x = i >= 0 ? i : -i;
			ans += mglen(-x, x, ly, ry);
		}
	}
	for (int i = ly; i <= ry; i++){
		if (!(i & 1)){
			int y = i >= 0 ? i : -i;
			ans += mglen(-y+1, y-1, lx, rx);
		}
	}
	cout << ans << '\n';
	return 0;
}

