#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long t;
int a[25];
int gcd(long long x, long long y){
	if (x % y == 0) return y;
	return gcd(y, x % y);
}
long long lcm(long long x, long long y){
	return x * y / gcd(x, y);
}
long long dfs(int x, long long lm){
	if (lm > t) return 0;
	if (x > n){
		return t / lm;
	} else {
		return dfs(x+1, lm) - dfs(x+1, lcm(lm, a[x]));
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << dfs(1, 1) << '\n';
	return 0;
}

