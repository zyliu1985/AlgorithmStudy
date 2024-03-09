#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int a[200005], b[200005], x[200005];
signed main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			long long t = a[i];
//			cout << t << ',';
			a[i] += max((long long)(0), min(a[i]-x[j], b[j]-x[j]));
			x[j] = max(x[j], t);
//			cout << a[i] << ',' << x[j] << ' ';
		}
		cout << a[i] << endl;
	}
}