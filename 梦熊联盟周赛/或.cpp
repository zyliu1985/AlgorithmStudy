#include <iostream>
#include <cstring>
using namespace std;

int cnt;
bool Dl[35];
void chai(int x){
	memset(Dl, false, sizeof(Dl));
	cnt = -1;
	while (x > 0){
		Dl[++cnt] = x % 2;
		x /= 2;
	}
}
int main(){
	freopen("or.in", "r", stdin);
	freopen("or.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int l, r;
		cin >> l >> r;
		chai(l);
		int x = 1, ans = 0;
		for (int i = 0; i <= 30; i++){
			if (Dl[i] || r - l >= x - l % x)
				ans += x;
			x *= 2;
		}
		cout << ans << endl;
	}
	return 0;
}
