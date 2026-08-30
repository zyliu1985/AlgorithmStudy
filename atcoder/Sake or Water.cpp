#include <iostream>
#include <algorithm>
using namespace std;

int a[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	long long x;
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	long long sum = 0;
	for (int i = k; i >= 1; i--){
		sum += a[i];
		if (sum >= x){
			cout << n - i + 1 << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}

