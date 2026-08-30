#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int tm, n, m;
		cin >> tm >> n >> m;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		sort(a+1, a+n+1);
		for (int i = 1; i <= m; i++)
			tm -= a[i];
		if (tm < 0) cout << -1 << '\n';
		else cout << tm / 40 << '\n';
	}
	return 0;
}



