#include <iostream>
#include <algorithm>
using namespace std;

long long x[500005], d[500005];
bool cmp(long long a, long long b){
	return a > b;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	sort(x+1, x+n+1);
	for (int i = 1; i < n; i++)
		d[i] = x[i+1] - x[i];
	sort(d+1, d+n, cmp); 
	long long ans = x[n] - x[1];
	for (int i = 1; i < m; i++)
		ans -= d[i];
	cout << ans << '\n';
	return 0;
}



