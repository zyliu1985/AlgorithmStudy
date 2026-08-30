#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;
int h, w, k, x1, y1, x2, y2;
struct node{
	int n, m;
	long long val[5][5];
	friend node operator * (const node x, const node y){
		node z;
		if (x.m != y.n) exit(9);
		z.n = x.n, z.m = y.m;
		for (int i = 1; i <= x.n; i++)
			for (int j = 1; j <= y.m; j++){
				z.val[i][j] = 0;
				for (int k = 1; k <= x.m; k++)
					z.val[i][j] = (z.val[i][j] + (x.val[i][k] * y.val[k][j]) % mod) % mod;
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
// {(0,0),(0,1),(1,0),(1,1)}
// (h+w-4  1     1    0)
// (w-1    h-2   0    1)
// (h-1    0     w-2  1)
// (0      h-1   w-1  0)
node power, base, l;
node qpow(node x, int up){
	if (up == 0) return l;
	if (up & 1) return qpow(x * x, up / 2) * x;
	else return qpow(x * x, up / 2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
	l.n = l.m = 4;
	for (int i = 1; i <= 4; i++)
		l.val[i][i] = 1;
	power.n = power.m = 4;
	power.val[1][1] = (h+w-4) % mod; power.val[1][2] = 1    ; power.val[1][3] = 1    ; power.val[1][4] = 0    ;
	power.val[2][1] = (w-1) % mod  ; power.val[2][2] = (h-2) % mod  ; power.val[2][3] = 0    ; power.val[2][4] = 1    ; 
	power.val[3][1] = (h-1) % mod  ; power.val[3][2] = 0    ; power.val[3][3] = (w-2) % mod  ; power.val[3][4] = 1    ; 
	power.val[4][1] = 0    ; power.val[4][2] = (h-1) % mod  ; power.val[4][3] = (w-1) % mod  ; power.val[4][4] = 0    ; 
	base.n = 1, base.m = 4;
	if (x1 != x2 && y1 != y2) base.val[1][1] = 1;
	if (x1 != x2 && y1 == y2) base.val[1][2] = 1;
	if (x1 == x2 && y1 != y2) base.val[1][3] = 1;
	if (x1 == x2 && y1 == y2) base.val[1][4] = 1;
	base = base * qpow(power, k);
	cout << base.val[1][4] << '\n';
	return 0;
}

