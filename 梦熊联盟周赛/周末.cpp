#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, a, b;
		cin >> n >> a >> b;
		int sum = a + b;
		int l = 1, r = sum;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			x %= sum;
			l = max(l, (sum-x+1) % sum + 1);
			r = min(r, (a+sum-x) % sum + 1);
			if (l == 7) l = 0;
			cout << l << ' ' << r << endl;
		}
		if (l <= r) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}