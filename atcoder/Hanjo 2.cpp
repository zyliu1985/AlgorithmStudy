#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod = 998244353;
struct sqr{
	int n, m;
	long long val[70][70];
	void clear(){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				val[i][j] = 0;
	}
	friend sqr operator * (const sqr x, const sqr y){
		sqr z;
		if (x.m != y.n)
			exit(9);
		z.n = x.n;
		z.m = y.m;
		z.clear();
		for (int i = 0; i < x.n; i++)
			for (int j = 0; j < y.m; j++)
				for (int k = 0; k < x.m; k++)
					z.val[i][j] = (z.val[i][j] + x.val[i][k] * y.val[k][j] % mod) % mod;
		return z;
	}
} mul, str;
long long dp[10][1 << 6];
int h;
long long w;
void calc(int x){
	memset(dp, 0, sizeof(dp));
	dp[1][x] = 1;
	for (int i = 1; i <= h; i++)
		for (int j = 0; j < (1 << h); j++){
			if ((j >> (i-1)) & 1){
				dp[i+1][j^(1 << (i-1))] = (dp[i+1][j^(1 << (i-1))] + dp[i][j]) % mod;
			} else {
				if (!((j >> i) & 1))
					dp[i+2][j] = (dp[i+2][j] + dp[i][j]) % mod;
				dp[i+1][j|(1 << (i-1))] = (dp[i+1][j|(1 << (i-1))] + dp[i][j]) % mod;
				dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
			}
		}
	for (int j = 0; j < (1 << h); j++)
		mul.val[x][j] = (mul.val[x][j] + dp[h+1][j]) % mod;
}
sqr qpow(sqr x, long long up){
	if (up == 1) return x;
	if (up & 1) return qpow(x * x, up / 2) * x;
	else return qpow(x * x, up / 2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> h >> w;
	mul.n = mul.m = (1 << h);
	mul.n = mul.m = (1 << h);
	for (int i = 0; i < (1 << h); i++)
		calc(i);
//	for (int i = 0; i < (1 << h); i++){
//		for (int j = 0; j < (1 << h); j++)
//			cout << mul.val[i][j] << ' ';
//		cout << '\n';
//	}
//	return 0;
	str.n = 1, str.m = (1 << h);
	str.val[0][0] = 1;
	str = str * qpow(mul, w);
	cout << str.val[0][0] << '\n';
	return 0;
}

