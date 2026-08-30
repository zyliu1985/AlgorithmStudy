#include <iostream>
#include <algorithm>
using namespace std;

const int B = 200;
int c[50005];
struct quest{
	long long l, r, id;
	long long du, dp;
	int _gcd(long long x, long long y){
		if (x % y == 0) return y;
		return _gcd(y, x % y);
	}
	void gcd(){
		int gd = _gcd(du, dp);
		du /= gd, dp /= gd;
	}
} q[50005];
bool cmp1(quest x, quest y){
	return x.r < y.r;
}
bool cmp2(quest x, quest y){
	return x.l < y.l;
}
bool cmp3(quest x, quest y){
	return x.id < y.id;
}
int num[50005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= m; i++){
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
		q[i].du = 0, q[i].dp = 1;
	}
	sort(q+1, q+m+1, cmp1);
	for (int L = 1; L <= n; L += B){
		int R = min(n, L + B - 1);
		int idl = lower_bound(q+1, q+m+1, quest{0, L, 0, 0, 1}, cmp1) - q;
		int idr = upper_bound(q+1, q+m+1, quest{0, R, 0, 0, 1}, cmp1) - q - 1;
		sort(q+idl, q+idr+1, cmp2);
		for (int i = 1; i <= n; i++)
			num[i] = 0;
		long long now = 0;
		for (int i = q[idl].l; i <= q[idl].r; i++)
			now += num[c[i]]++;
		q[idl].du = now;
		if (q[idl].l == q[idl].r) q[idl].dp = 1;
		else q[idl].dp = (q[idl].r - q[idl].l + 1) * (q[idl].r - q[idl].l) / 2;
		q[idl].gcd();
		for (int i = idl+1; i <= idr; i++){
			// ÍÆr
			if (q[i-1].r <= q[i].r){
				for (int j = q[i-1].r+1; j <= q[i].r; j++)
					now += num[c[j]]++;
			} else {
				for (int j = q[i].r+1; j <= q[i-1].r; j++)
					now -= --num[c[j]];
			}
			// ÍÆl
			for (int j = q[i-1].l; j < q[i].l; j++)
				now -= --num[c[j]]; 
			q[i].du = now;
			if (q[i].l == q[i].r) q[i].dp = 1;
			else q[i].dp = (q[i].r - q[i].l + 1) * (q[i].r - q[i].l) / 2;
			q[i].gcd();
		}
	}
	sort(q+1, q+m+1, cmp3);
	for (int i = 1; i <= m; i++)
		cout << q[i].du << '/' << q[i].dp << '\n';
	return 0;
}

