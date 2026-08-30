#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long a[105][1005], maxa[105], sumax;
long long t[105];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int T;
	cin >> T;
	while (T--){
		memset(maxa, 0, sizeof(maxa));
		sumax = 0;
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++)
				cin >> a[i][j], maxa[i] = max(maxa[i], a[i][j]);
			sumax += maxa[i];
		}
		long long ans = 0;
		for (int j = 1; j <= m; j++){
			for (int i = 1; i <= n; i++)
				t[i] = maxa[i] - a[i][j];
			sort(t+1, t+n+1);
			long long now = sumax;
			for (int i = 1; i <= n / 2 + 1; i++)
				now -= t[i];
			ans = max(ans, now);
		}
		cout << ans << '\n';
	} 
	return 0;
}



