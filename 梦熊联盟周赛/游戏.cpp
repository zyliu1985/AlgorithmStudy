#include <iostream>
using namespace std;

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout); 
	int l, r;
	cin >> l >> r;
	int ans = 0;
	while (r > 1){
		r /= 2;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
