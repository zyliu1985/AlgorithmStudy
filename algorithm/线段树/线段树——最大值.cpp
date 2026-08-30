#include <iostream>
using namespace std;

struct node{
	long long l, r, val, laz;
} tr[4 * 100005];
long long n, a[100005];
void push_up(int x){
	tr[x].val = max(tr[x * 2].val, tr[x * 2 + 1].val) + tr[x].laz;
}
void push_down(int x){
	tr[x * 2].val += tr[x].laz;
	tr[x * 2].laz += tr[x].laz;
	tr[x * 2 + 1].val += tr[x].laz;
	tr[x * 2 + 1].laz += tr[x].laz;
	tr[x].laz = 0;
}
void build(int x = 1, int l = 1, int r = n){
	tr[x].l = l, tr[x].r = r;
	if (l == r){
		tr[x].val = a[l];
		return;
	}
	build(x * 2, l, (l + r) / 2);
	build(x * 2 + 1, (l + r) / 2 + 1, r);
	push_up(x);
}
void add_one(int id, long long u, int x = 1){
	if (tr[x].l == tr[x].r){
		tr[x].val += u;
		return;
	}
	int mid = (tr[x].l + tr[x].r) / 2;
	if (id <= mid)
		add_one(id, u, x * 2);
	else
		add_one(id, u, x * 2 + 1);
	push_up(x); 
}
void add(int l, int r, long long u, int x = 1){
	if (tr[x].r < l || tr[x].l > r) return;
	if (tr[x].l >= l && tr[x].r <= r){
		tr[x].val += u;
		tr[x].laz += u;
		return;
	}
	push_down(x);
	add(l, r, u, x * 2);
	add(l, r, u, x * 2 + 1);
	push_up(x);
}
long long quary_one(int id, int x = 1){
	if (tr[x].l == tr[x].r) return tr[x].val;
	int mid = (tr[x].l + tr[x].r) / 2;
	push_down(x);
	if (id <= mid)
		return quary_one(id, x * 2);
	else
		return quary_one(id, x * 2 + 1);
}
long long quary(int l, int r, int x = 1){
	if (tr[x].r < l || tr[x].l > r) return -1e18;
	if (tr[x].l >= l && tr[x].r <= r) return tr[x].val;
	push_down(x);
	long long re = -1e18;
	re = max(re, quary(l, r, x * 2));
	re = max(re, quary(l, r, x * 2 + 1));
	return re;
}
int main(){
	 
	return 0;
}


