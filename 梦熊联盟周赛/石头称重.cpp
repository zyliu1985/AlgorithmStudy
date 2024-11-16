#include <iostream>
using namespace std;

long long w[55];
long long k;
int main(){
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	cin >> k;
	k--; 
	long long ans = 0;
	int cur = 1;
	while (k > 0){
		if (cur > n){
			cout << -1 << endl;
			return 0;
		}
		if (k & 1) ans += w[cur];
		k /= 2;
		cur++;
	}
	cout << ans << endl;
	return 0;
}
