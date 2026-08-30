#include <iostream>
#include <algorithm>
using namespace std;

int num[20];
int main(){
	freopen("andor.in", "r", stdin);
	freopen("andor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		for (int j = 0; j <= 19; j++){
			num[j] += x & 1;
			x >>= 1;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		long long now = 0;
		for (int j = 0; j <= 19; j++)
			if (num[j]){
				now += 1 << j;
				num[j]--;
			}
		ans += now * now;
	}
	cout << ans << '\n';
	return 0;
}

