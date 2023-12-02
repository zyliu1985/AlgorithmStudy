#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int h[1000005], l[1000005];
int hh, ll;
signed main(){
	int r, c, n, ans = 0;
	cin >> r >> c >> n;
	for (int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		h[i] = x;
		l[i] = y;
	}
	sort(h+1, h+n+1);
	sort(l+1, l+n+1);
	// …®√Ëh
	for (int i = 1; i <= n; i++){
		if (h[i] != h[i-1]) hh++;
	}
	// …®√Ël
	for (int i = 1; i <= n; i++){
		if (l[i] != l[i-1]) ll++;
	}
	cout << hh*c + ll*r - hh*ll << endl;
	return 0;
}