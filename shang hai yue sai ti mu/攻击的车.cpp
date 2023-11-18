#include <iostream>
#define int long long
using namespace std;

bool h[10000005], l[10000005];
int hh, ll;
signed main(){
	int r, c, n, ans = 0;
	cin >> r >> c >> n;
	for (int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		if (!h[x]) hh++;
		if (!l[y]) ll++;
		h[x] = true;
		l[y] = true;
	}
	cout << hh*c + ll*r - hh*ll << endl;
	return 0;
}