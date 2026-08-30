#include <iostream>
#include <algorithm>
using namespace std;

int a[200005], zak[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i >= 1; i--)
		if (a[i] <= i) zak[i - a[i] + 1]++;
//	for (int i = 1; i <= n; i++)
//		cout << zak[i] << ' '; 
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		if (i + a[i] + 1 <= n) ans += zak[i + a[i] + 1];
	cout << ans << '\n';
	return 0;
}
