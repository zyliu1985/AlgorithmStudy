#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 8000005;
const long long INV2 = 500000004;
int cur;
int lc[maxn], rc[maxn];
long long l[maxn], r[maxn];
long long ans[maxn], lst[maxn], empt[maxn];
inline int build(long long lt, long long rt){
//	cout << "add: " << lt << ',' << rt << '\n';
	cur++;
	l[cur] = lt;
	r[cur] = rt;
	ans[cur] = 0;
	lst[cur] = 0;
	empt[cur] = rt - lt + 1;
	return cur;
}
inline int lch(int x){
	if (lc[x]) return lc[x];
	return lc[x] = build(l[x], (l[x] + r[x]) / 2);
}
inline int rch(int x){
	if (rc[x]) return rc[x];
	return rc[x] = build((l[x] + r[x]) / 2 + 1, r[x]);
}

long long val(long long lt, long long rt){
	if (lt > rt) return 0;
	return ((lt + rt) % mod) * ((rt - lt + 1) % mod) % mod * INV2 % mod;
}
long long calc(int x, long long w){
	if (w == 0) return ans[x];
	if (empt[x] == r[x] - l[x] + 1) return val(l[x], l[x] + w - 1);
	if (w == empt[x]) return val(l[x], r[x]);
//	if (r[x] <= 200) cout << "(" << l[x] << ", " << r[x] << "): " << ans[x] << ',' << w << "\n";
	if (l[x] == r[x]){
		if (w) return (l[x] % mod);
		else return ans[x];
	}
	if (w > empt[lch(x)]) return (val(l[lch(x)], r[lch(x)]) + calc(rch(x), w - empt[lch(x)] + lst[lch(x)])) % mod;
	else return (calc(lch(x), w) + (ans[x] - ans[lch(x)] + mod) % mod) % mod;
}
void pushup(int x){
	if (!lc[x]){
		ans[x] = ans[rch(x)];
		lst[x] = lst[rch(x)];
		empt[x] = (r[x] - l[x] + 2) / 2 + empt[rch(x)];
		return;
	}
	if (!rc[x]){
		if (lst[lch(x)] >= (r[x] - l[x] + 1) / 2){
			ans[x] = (ans[lch(x)] + val((l[x] + r[x]) / 2 + 1, r[x])) % mod;
			lst[x] = lst[lch(x)] - (r[x] - l[x] + 1) / 2;
			empt[x] = empt[lch(x)];
		} else {
			ans[x] = (ans[lch(x)] + val((l[x] + r[x]) / 2 + 1, (l[x] + r[x]) / 2 + lst[lch(x)])) % mod;
			lst[x] = 0;
			empt[x] = empt[lch(x)] + (r[x] - l[x] + 1) / 2 - lst[lch(x)];
		}
	}
	if (lst[lch(x)] >= empt[rch(x)]){
//		cout << l[x] << ',' << r[x] << ": case1\n"; 
//		cout << lst[rch(x)] << '\n'; 
		ans[x] = (ans[lch(x)] + val(l[rch(x)], r[rch(x)])) % mod;
		lst[x] = lst[rch(x)] + lst[lch(x)] - empt[rch(x)];
		empt[x] = empt[lch(x)];
	} else {
//		cout << l[x] << ',' << r[x] << ": case2\n"; 
		ans[x] = (ans[lch(x)] + calc(rch(x), lst[lch(x)])) % mod;
		lst[x] = lst[rch(x)];
		empt[x] = empt[lch(x)] + empt[rch(x)] - lst[lch(x)];
	}
}
void change(long long pos, int num, int x = 1){
	if (l[x] == r[x]){
		if (num){
			ans[x] = l[x];
			lst[x] = num-1;
			empt[x] = 0;
		} else {
			ans[x] = 0;
			lst[x] = 0;
			empt[x] = 1;
		}
		return;
	}
	long long mid = (l[x] + r[x]) / 2;
	if (pos <= mid) change(pos, num, lch(x));
	else change(pos, num, rch(x));
	pushup(x);
//	cout << "[" << l[x] << ", " << r[x] << "]: " << ans[x] << ',' << lst[x] << ',' << empt[x] << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	cur = 1;
	l[1] = 1, r[1] = 1e14;
	empt[1] = 1e14;
	while (q--){
		long long d;
		int b;
		cin >> d >> b;
		change(d, b);
		cout << (ans[1] + val(r[1] + 1, r[1] + lst[1])) % mod << '\n';
//		cout << cur << '\n';
	}
	return 0;
}

