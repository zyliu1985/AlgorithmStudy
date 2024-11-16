#include <iostream>
using namespace std;

int main(){
//	freopen("dog.in", "r", stdin);
//	freopen("dog.out", "w", stdout);
	int n, x;
	cin >> n >> x;
	int maxn = -1e9, maxd = 0;
	for (int i = 1; i <= n; i++){
		int d, h;
		cin >> d >> h;
		maxn = max(d - h, maxn);
		maxd = max(d, maxd);
	}
	x -= maxd;
	if (x <= 0)
		cout << 1 << endl;
	else if (maxn <= 0)
		cout << -1 << endl;
	else
		cout << (x + maxn - 1) / maxn + 1 << endl;
	return 0;
}
