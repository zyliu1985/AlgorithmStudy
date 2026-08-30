#include <iostream>
#include <algorithm>
using namespace std;

int d[200005];
int cur;
struct node{
	int lt, rt;
} a[200005];
bool cmp(node x, node y){
	return x.lt < y.lt;
}
int num;
const int mod = 1e9 + 7;
int pow2(int up, long long x = 2){
	if (up == 0) return 1;
	if (up & 1) return pow2(up / 2, x * x % mod) * x % mod;
	else return pow2(up / 2, x * x % mod);
}
int calc(int l, int r){
	long long re = 0;
	int pl = upper_bound(a+1, a+num+1, node{l, l}, cmp) - a - 1;
	if (l <= a[pl].rt){
		re = (re + (pow2(a[pl].rt - l + 1) - 1) * pow2) % mod;
	}
	l = a[pl+1].lt;
	int pr = upper_bound(a+1, a+num+1, node{r, r}, cmp) - a - 1;
	if (r >= a[pr].lt){
		re = (re + pow2(r - a[pr].lt + 1) - 1) % mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	freopen("flip.in", "r", stdin);
	freopen("flip.out", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++){
		int l, r;
		cin >> l >> r;
		d[++cur] = l;
		d[++cur] = r;
	}
	sort(d+1, d+cur+1);
	for (int i = 1; i <= cur; i += 2){
		a[++num].lt = d[i];
		a[num].rt = d[i+1];
	}
	a[0].rt = -1;
	a[num+1].lt = 1e9;
	a[num+1].rt = 1e9-1;
	while (q--){
		int l, r, k;
		cin >> l >> r >> k;
		
	}
	return 0;
}
