#include <iostream>
using namespace std;

struct node{
	long long l, r, val;
} tr[4 * 100005];
long long n, a[100005];
void push_up(int x){
	tr[x].val = tr[x * 2].val + tr[x * 2 + 1].val;
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
void change_one(int id, long long u, int x = 1){
	if (tr[x].l == tr[x].r){
		tr[x].val += u;
		return;
	}
	int mid = (tr[x].l + tr[x].r) / 2;
	if (id <= mid)
		change_one(id, u, x * 2);
	else
		change_one(id, u, x * 2 + 1);
	push_up(x); 
}
long long quary(int l, int r, int x = 1){
	if (tr[x].r < l || tr[x].l > r) return 0;
	if (tr[x].l >= l && tr[x].r <= r) return tr[x].val;
	long long re = 0;
	re += quary(l, r, x * 2);
	re += quary(l, r, x * 2 + 1);
	return re;
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build();
	int m;
	cin >> m;
	while (m--){
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 1) change_one(a, b);
		else cout << quary(a, b) << '\n';
	} 
	return 0;
}


