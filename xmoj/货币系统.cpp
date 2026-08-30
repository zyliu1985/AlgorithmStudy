#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[105];
int f[25005];
int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		f[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = a[i]; j <= 25000; j++)
				f[j] += f[j-a[i]];
		int ans = n;
		for (int i = 1; i <= n; i++)
			if (f[a[i]] > 1) ans--;
		cout << ans << "\n";
	}
	return 0;
}

