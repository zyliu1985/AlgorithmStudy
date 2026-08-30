#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int mod = 998244353;
int qpow(long long x, int up){
	if (up == 0) return 1;
	if (up & 1) return qpow(x * x % mod, up / 2) * x % mod;
	else return qpow(x * x % mod, up / 2);
}
int frac(int a, int b){
	return (a * 1ll * qpow(b, mod - 2)) % mod;
}
int n, m;
int a[200005], tr[4 * 200005], l[4 * 200005], r[4 * 200005], lz[4 * 200005];
void push_up(int x){
	if (lz[x]) tr[x] = lz[x] * (r[x] - l[x] + 1) % mod;
	else tr[x] = (tr[x * 2] + tr[x * 2 + 1]) % mod;
}
void push_down(int x){
	if (lz[x]){
		lz[x * 2] = lz[x];
		lz[x * 2 + 1] = lz[x];
		tr[x * 2] = lz[x] * (r[x * 2] - l[x * 2] + 1) % mod;
		tr[x * 2 + 1] = lz[x] * (r[x * 2 + 1] - l[x * 2 + 1] + 1) % mod;
		lz[x] = 0;
	}
}
void init(int x = 1, int nl = 1, int nr = n){
	l[x] = nl, r[x] = nr;
	if (l[x] == r[x]){
		tr[x] = a[l[x]];
		return;
	}
	int mid = (nl + nr) / 2;
	init(x * 2, nl, mid);
	init(x * 2 + 1, mid + 1, nr);
	push_up(x);
}
void change(int cl, int cr, int cv, int x = 1){
	if (r[x] < cl || cr < l[x]) return;
	if (cl <= l[x] && r[x] <= cr){
		lz[x] = cv;
		tr[x] = lz[x] * (r[x] - l[x] + 1) % mod;
		return;
	}
	change(cl, cr, cv, x * 2);
	change(cl, cr, cv, x * 2 + 1);
	push_up(x);
}
int quary(int ql, int qr, int x = 1){
//	cout << l[x]  << ' ' << r[x] << '\n';
	if (r[x] < ql || qr < l[x]) return 0;
	if (ql <= l[x] && r[x] <= qr) return tr[x];
	push_down(x);
	return (quary(ql, qr, x * 2) + quary(ql, qr, x * 2 + 1)) % mod;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	init();
//		for (int i = 1; i <= n; i++)
//			cout << quary(i, i) << '\n';
	while (m--){
		int ll, rr;
		cin >> ll >> rr;
		int to = frac(quary(ll, rr), rr - ll + 1);
		change(ll, rr, to);
		
	}
	for (int i = 1; i <= n; i++)
		cout << quary(i, i) << ' ';
	return 0;
}

