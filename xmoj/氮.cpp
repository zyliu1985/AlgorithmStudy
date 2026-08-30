#include <iostream>
#include <algorithm>
using namespace std;

int b[500005][3];
// 0: 0 0
// 1: 0 1
// 2: 1 1
int main(){
	freopen("N.in", "r", stdin);
	freopen("N.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int m;
		cin >> m;
		for (int j = 1; j <= m; j++){
			bool a;
			cin >> a;
			if (a){
				b[i][2]++;
				if (b[i][0] && b[i][1]) b[i][1] = max(b[i][1] + 1, b[i][0] + 1);
				else if (b[i][0]) b[i][1] = max(b[i][1], b[i][0] + 1);
			} else {
				b[i][0]++;
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//		cout << b[i][0] << ' ' << b[i][1] << ' ' << b[i][2] << '\n';
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += max(b[i][0], b[i][2]);
	int org = ans;
	for (int i = 1; i <= n; i++){
		ans = max(ans, org - max(b[i][0], b[i][2]) + b[i][1]);
	}
	cout << ans << '\n';
	return 0;
}

