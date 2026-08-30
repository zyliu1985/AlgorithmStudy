#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int a[1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, sum = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], sum += a[i];
	for (int i = 1; i <= n; i++)
		ans += (n * a[i] - sum) * (n * a[i] - sum);
	cout << ans / n << '\n';
	return 0;
}

