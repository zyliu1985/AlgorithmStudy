// 30
#include <iostream>
#include <cmath>
using namespace std;

int a[200005], s[200005];
int main(){
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 1e9;
	for (int x = 1; x <= 100; x++)
		for (int y = x; y <= 100; y++)
			for (int z = y; z <= 100; z++){
				int sum = 0;
				for (int i = 1; i <= n; i++)
					sum = max(sum, min(abs(a[i] - x), min(abs(a[i] - y), abs(a[i] - z))));
				ans = min(ans, sum);
			}
	cout << ans << endl;
	return 0;
}
