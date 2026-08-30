#include <iostream>
#include <algorithm>
using namespace std;

int p[10005], a[10005], b[10005], sumb[10005], f[10005][1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i] >> a[i] >> b[i];
		sumb[i] = sumb[i-1] + b[i];
	}
	for (int j = 0; j <= 1000; j++)
		f[n+1][j] = j;
	for (int i = n; i >= 1; i--)
		for (int j = 0; j <= 1000; j++)
			if (p[i] >= j) f[i][j] = f[i+1][j + a[i]];
			else f[i][j] = f[i+1][max(0, j - b[i])];
//	cout << f[18][389] << ' ' << f[19][158] << ' ' << f[20][573] << 
	int q;
	cin >> q;
	while (q--){
		int x, start = 1;
		cin >> x;
		if (x > 500){
			int t = lower_bound(sumb+1, sumb+n+1, x - 500) - sumb;
			if (t > n){
				cout << x - sumb[n] << '\n';
				continue;
			} 
//			if (x == 6332) cout << t << "-----\n";
			x = max(0, x - sumb[t]);
//			cout << x << "****\n";
			start = t + 1;
		}
//		cout << start << ' ' << x << '\n';
		cout << f[start][x] << '\n';
	}
	return 0;
}

