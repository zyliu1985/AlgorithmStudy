#include <iostream>
#include <algorithm>
using namespace std;

int n, q, m;
// ÏÈ³Ëºó¼Ó
long long a[100005], tr[400005], lz1[400005], lz2[400005];
void push_up(int x, int l, int r){
	tr[x] = (((tr[x*2] + tr[x*2+1]) % m) * lz1[x] % m + lz2[x] * (r - l + 1) % m) % m;
}
void push_down(int x, int l, int r){
	int mid = (l + r) / 2;
	if (lz1[x] > 1 || lz2[x]){
		tr[x*2] = (tr[x*2] * lz1[x] % m + lz2[x] * (mid - l + 1) % m) % m;
		tr[x*2+1] = (tr[x*2+1] * lz1[x] % m + lz2[x] * (r - mid) % m) % m;
		lz2[x*2] = (lz2[x*2] * lz1[x] % m + lz2[x]) % m;
		lz2[x*2+1] = (lz2[x*2+1] * lz1[x] % m + lz2[x]) % m;
		lz1[x*2] = lz1[x*2] * lz1[x] % m;
		lz1[x*2+1] = lz1[x*2+1] * lz1[x] % m;
		lz1[x] = 1;
		lz2[x] = 0; 
	}
}
void build(int x = 1, int l = 1, int r = n){
	lz1[x] = 1;
	if (l == r){
		tr[x] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(x*2, l, mid);
	build(x*2+1, mid+1, r);
	push_up(x, l, r); 
} 
// mul
void cge1(int cl, int cr, int w, int x = 1, int l = 1, int r = n){
	if (r < cl || l > cr) return;
	else if (cl <= l && r <= cr){
		tr[x] = tr[x] * w % m;
		lz2[x] = lz2[x] * w % m;
		lz1[x] = lz1[x] * w % m;
		return;
	}
	push_down(x, l, r);
	int mid = (l + r) / 2;
	cge1(cl, cr, w, x*2, l, mid);
	cge1(cl, cr, w, x*2+1, mid+1, r);
	push_up(x, l, r);
}
// add
void cge2(int cl, int cr, long long w, int x = 1, int l = 1, int r = n){
	if (r < cl || l > cr) return;
	else if (cl <= l && r <= cr){
		tr[x] = (tr[x] + w * (r - l + 1) % m) % m;
		lz2[x] = (lz2[x] + w) % m;
		return;
	}
	push_down(x, l, r);
	int mid = (l + r) / 2;
	cge2(cl, cr, w, x*2, l, mid);
	cge2(cl, cr, w, x*2+1, mid+1, r);
	push_up(x, l, r);
}
int query(int ql, int qr, int x = 1, int l = 1, int r = n){
	if (r < ql || l > qr) return 0;
	else if (ql <= l && r <= qr) return tr[x];
	push_down(x, l, r);
	int mid = (l + r) / 2;
	long long re = 0;
	re = (re + query(ql, qr, x*2, l, mid)) % m;
	re = (re + query(ql, qr, x*2+1, mid+1, r)) % m;
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build();
	while (q--){
		int c;
		cin >> c;
		if (c == 1){
			int l, r, w;
			cin >> l >> r >> w;
			cge1(l, r, w);
		} else if (c == 2){
			int l, r, w;
			cin >> l >> r >> w;
			cge2(l, r, w);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << '\n';
		}
	}
	return 0;
}

