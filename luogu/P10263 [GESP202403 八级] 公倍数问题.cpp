#include <iostream>
#include <algorithm>
using namespace std;

long long a[1000005], b[1000005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= k; j += i)
			a[j]++;
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= k; j += i)
			b[j]++; 
	long long ans = 0;
	for (long long i = 1; i <= k; i++){
		ans += a[i] * b[i] * i;
	}
	cout << ans << '\n';
	return 0;
}



