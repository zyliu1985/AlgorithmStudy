#include <iostream>
using namespace std;

int box[1000005];
int ans = 1e9;
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		if (box[a] != 0) ans = min(ans, i - box[a] + 1);
		box[a] = i;
	}
	if (ans == 1e9) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}


