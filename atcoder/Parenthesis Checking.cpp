#include <iostream>
#include <algorithm>
using namespace std;

string s;
int n, q;
const int N = 2e5 + 5;
int sum[4 * N], mins[4 * N];
void push_up(int x){
	sum[x] = sum[x*2] + sum[x*2+1];
	mins[x] = min(mins[x*2], sum[x*2]+mins[x*2+1]);
}
void build(int x = 1, int l = 1, int r = n){
	if (l == r){
		int val = s[l] == '(' ? 1 : -1;
		sum[x] = mins[x] = val;
		return;
	}
	int mid = (l + r) / 2;
	build(x*2, l, mid);
	build(x*2+1, mid+1, r);
	push_up(x);
}
void cge(int cx, int x = 1, int l = 1, int r = n){
	if (l == cx && r == cx){
		sum[x] = -sum[x];
		mins[x] = -mins[x];
		return;
	}
	int mid = (l + r) / 2;
	if (cx <= mid) cge(cx, x*2, l, mid);
	else cge(cx, x*2+1, mid+1, r);
	push_up(x);
}
int find(int cx, int x = 1, int l = 1, int r = n){
	if (l == cx && r == cx) return sum[x];
	int mid = (l + r) / 2;
	if (cx <= mid) return find(cx, x*2, l, mid);
	else return find(cx, x*2+1, mid+1, r);
}
int check(int cl, int cr, int x = 1, int l = 1, int r = n, int presum = 0){
	if (r < cl || l > cr) return 0;
	else if (cl <= l && r <= cr){
		if (mins[x] + presum < 0) return 1e9;
		else return sum[x];
	}
	int mid = (l + r) / 2;
	int re = check(cl, cr, x*2, l, mid, presum);
	if (re > n) return 1e9;  
	re += check(cl, cr, x*2+1, mid+1, r, presum + re);
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q >> s;
	s = ' ' + s;
	build();
	while (q--){
		int c, l, r;
		cin >> c >> l >> r;
		if (c == 1){
			if (find(l) != find(r)){
				cge(l), cge(r);
			}
		} else {
			if (check(l, r) == 0) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}

