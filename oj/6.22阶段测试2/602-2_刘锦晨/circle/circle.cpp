#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int mod = 998244353;
long long n, ans;
long long fun(long long x){
	int t = sqrt(x);
	int y = x - t * t;
	long long s1 = 1;
	for (int i = 1; i <= t; i++)
		s1 = s1 * 3 % mod;
	long long s2 = 1;
	for (int i = 1; i <= t; i++)
		s2 = s2 * s1 % mod;
	long long s3 = 1;
	for (int i = 1; i <= y; i++)
		s3 = s3 * 3 % mod;
	return s2 * s3 % mod;
}
//void dfs(int x, int last, int first){
//	if (x > n){
//		ans++;
//		return;
//	}
//	for (int i = 1; i <= 4; i++){
//		if (x != 1 && i == last) continue;
//		if (x == n && i == first) continue;
//		if (x == 1) dfs(x+1, i, i);
//		else dfs(x+1, i, first);
//	}
//}
int main(){
//	freopen("circle.in", "r", stdin);
//	freopen("circle.out", "w", stdout);
	cin >> n;
	if (n & 1)
		cout << ((8 * fun(n-2)) % mod + fun(n-2) + 1) % mod << endl;
	else
		cout << ((8 * fun(n-2)) % mod + fun(n-2) + 3) % mod << endl;
	return 0;
}
