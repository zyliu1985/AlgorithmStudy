#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;
const int inv2 = 499122177;
int n;
string s;
int pow2[50005];
int p[25], cur;
void chai(int x){
	int now = 2;
	while (x > 1){
		if (x % now == 0) p[++cur] = now;
		while (x % now == 0){
			x /= now;
		}
		now++;
	}
}
int calc(int m){
	bool vis[50005];
	long long re = pow2[m];
	for (int i = 0; i < m; i++)
		vis[i] = false;
	for (int i = 1; i <= n; i++)
		if (s[i] == '.' && !vis[i % m]){
			vis[i % m] = true;
			re = (re * inv2) % mod;
		}
	return re;
}
int gcd(int x, int y){
	if (x % y == 0) return y;
	return gcd(y, x % y);
}
int dfs(int x, int gd){
	if (x > cur){
		if (gd == n) return 0;
		else return calc(gd);
	} else {
		return (dfs(x+1, gd) - dfs(x+1, gcd(gd, n / p[x])) + mod) % mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;
	s = ' ' + s;
	pow2[0] = 1;
	for (int i = 1; i <= n / 2; i++)
		pow2[i] = pow2[i-1] * 2 % mod;
	chai(n);
	cout << mod - dfs(1, n) << '\n';
	return 0;
}
 
