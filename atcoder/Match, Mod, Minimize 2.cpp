#include <iostream>
#include <algorithm>
using namespace std;
 
int a[300005], b[300005];
bool cmp(int a, int b){
	return a > b;
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, m;
		long long sum = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i], sum += a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i], sum += b[i];
		sort(a+1, a+n+1, cmp), sort(b+1, b+n+1);
		for (int i = 1, j = 1; j <= n; i++){
			while (a[i] + b[j] < m && j <= n) j++;
			if (j > n) break;
			sum -= m;
			j++;
		}
//		if (sum < 0){
//			while (1);
//		}
		cout << sum << '\n';
	}
	return 0;
}



