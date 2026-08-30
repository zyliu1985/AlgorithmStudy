#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int n, m;
	bool val[25][25];
	friend node operator * (const node x, const node y){
		node z;
		if (x.m != y.n) exit(9);
		z.n = x.n, z.m = y.m;
		for (int i = 1; i <= x.n; i++)
			for (int j = 1; j <= y.m; j++){
				z.val[i][j] = 0;
				for (int k = 1; k <= x.m; k++)
					z.val[i][j] |= x.val[i][k] & y.val[k][j];
			}
		return z;
	}
	void print(){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++)
				cout << val[i][j] << ' ';
			cout << '\n';
		}
	}
};
node qpow(node x, int up){
	if (up == 0) return l;
	if (up & 1) return qpow(x * x, up / 2) * x;
	else return qpow(x * x, up / 2);
}
long long l[20005], r[20005];
node base, power;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= m; i++)
		cin >> l[i] >> r[i];
	l[m+1] = 1e18;
	power.n = power.m = b;
	for (int i = 1; i < b; i++)
		power[i][i+1] = true;
	for (int i = a; i <= b; i++)
		power[1][i] = true;
	base.n = 1, base.m = b;
	base.val[1][b] = 1;
	int now = 1;
	for (int i = 1; i <= m; i++){
		if (now < l[i]) base = base * qpow(power, l[i] - now - 1);
		now = max(l[i] - 1, now);
		// r[i] + b
		for (int j = 1; j <= b; j++)
			for (int k = a; k <= b; k++)
				if (now - b + j + k > r[i] && now - b + j + k < l[i+1]){
					base[now - b + j + k - r[i]] = 1;
				}
	}
	return 0;
}

