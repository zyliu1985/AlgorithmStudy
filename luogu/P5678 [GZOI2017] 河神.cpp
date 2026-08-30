#include <iostream>
#include <algorithm>
using namespace std;

const long long inf = (1ll << 63) - 1;
struct sqr{
	int n, m;
	long long val[105][105];
	void clear(){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				val[i][j] = 0;
	}
	friend sqr operator * (const sqr x, const sqr y){
		sqr z;
		z.n = x.n, z.m = y.m;
		z.clear();
		if (x.m != y.n) return z;
		for (int i = 1; i <= x.n; i++)
			for (int j = 1; j <= y.m; j++)
				for (int k = 1; k <= x.m; k++)
					z.val[i][j] |= x.val[i][k] & y.val[k][j];
		return z;
	}
} stat, base;
sqr qpow(sqr x, int up){
	if (up == 1) return x;
	if (up & 1) return qpow(x * x, up / 2) * x;
	else return qpow(x * x, up / 2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	n++;
	stat.n = 1, stat.m = k;
	base.n = k, base.m = k;
	for (int i = 1; i <= k; i++)
		cin >> stat.val[1][i];
	for (int i = 2; i <= k; i++)
		base.val[i][i-1] = inf;
	for (int i = 1; i <= k; i++)
		cin >> base.val[i][k];
	stat = stat * qpow(base, n - k);
	cout << stat.val[1][k] << '\n';
	return 0;
}

