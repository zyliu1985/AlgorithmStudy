#include <iostream>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;

int n, k;
struct node{
	int a, b, c;
} h[100005];
bool cmp(node x, node y){
	if (x.a != y.a) return x.a < y.a;
	if (x.b != y.b) return x.b < y.b;
	return x.c < y.c;
}
int f[100005], box[100005];
int tr[200005];
//void clear(){
//	for (int i = 1; i <= k; i++)
//		tr[i] = 0;
//}
void insert(int x){
	for (int i = x; i <= k; i += lowbit(i))
		tr[i]++;
}
void del(int x){
	for (int i = x; i <= k; i += lowbit(i))
		tr[i]--;
}
int query(int x){
	int re = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		re += tr[i];
	return re;
}
struct temp{
	int b, c, id;
} t[100005];
int cur;
bool cmp2(temp x, temp y){
	if (x.b != y.b) return x.b < y.b;
	return x.id < y.id;
}
void solve(int l, int r){
	if (l == r) return;
	int mid = (l + r) / 2;
	solve(l, mid), solve(mid+1, r);
	cur = 0;
	for (int i = l; i <= r; i++)
		t[++cur] = {h[i].b, h[i].c, i};
	sort(t+1, t+cur+1, cmp2);
	for (int i = 1; i <= cur; i++)
		if (t[i].id <= mid) insert(t[i].c);
		else f[t[i].id] += query(t[i].c);
	for (int i = 1; i <= cur; i++)
		if (t[i].id <= mid) del(t[i].c);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> h[i].a >> h[i].b >> h[i].c;
	sort(h+1, h+n+1, cmp);
//	cout << "sorted\n";
	int len = 0;
	for (int i = n; i >= 1; i--)
		if (h[i].a == h[i+1].a && h[i].b == h[i+1].b && h[i].c == h[i+1].c){
			len++;
			f[i] += len-1;
		} else {
			len = 1;
		}
//	for (int i = 1; i <= n; i++)
//		cout << h[i].a << ' ' << h[i].b << ' ' << h[i].c << '\n';
	solve(1, n);
	for (int i = 1; i <= n; i++)
		box[f[i]]++;
	for (int i = 0; i < n; i++)
		cout << box[i] << '\n';
	return 0;
}

