#include <iostream>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;

int n, m;
struct node{
	int v, t, id;
} b[100005];
bool cmp(node x, node y){
	return x.t > y.t;
}
int cur;
int v[100005], t[100005], id[100005];
int pre[100005], nxt[100005];
long long ans[100005];
void pre_ins(int x){
	for (int i = x; i <= n; i += lowbit(i))
		pre[i]++;
}
void pre_del(int x){
	for (int i = x; i <= n; i += lowbit(i))
		pre[i]--;
}
void nxt_ins(int x){
	x = n-x+1;
	for (int i = x; i <= n; i += lowbit(i))
		nxt[i]++;
}
void nxt_del(int x){
	x = n-x+1;
	for (int i = x; i <= n; i += lowbit(i))
		nxt[i]--;
}
int pre_query(int x){
	int re = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		re += pre[i];
	return re;
}
int nxt_query(int x){
	x = n-x+1;
	int re = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		re += nxt[i];
	return re;
}
void solve(int l, int r){
	if (l == r) return;
	int mid = (l + r) / 2;
	solve(l, mid), solve(mid+1, r);
	cur = 0;
	for (int i = l; i <= r; i++)
		b[++cur] = {v[i], t[i], i};
	sort(b+1, b+cur+1, cmp);
	for (int i = 1; i <= cur; i++)
		if (b[i].id <= mid){
			// search pre
			ans[b[i].t] += pre_query(b[i].v);
			nxt_ins(b[i].v);
		} else {
			// search nxt
			ans[b[i].t] += nxt_query(b[i].v);
			pre_ins(b[i].v);
		}
	for (int i = 1; i <= cur; i++)
		if (b[i].id <= mid){
			nxt_del(b[i].v);
		} else {
			pre_del(b[i].v);
		}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i], id[v[i]] = i;
	for (int i = 1; i <= m; i++){
		int x;
		cin >> x;
		t[id[x]] = i;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!t[i]) t[i] = m;
	solve(1, n);
	for (int i = m-1; i >= 1; i--)
		ans[i] += ans[i+1];
	for (int i = 1; i <= m; i++)
		cout << ans[i] << '\n';
	return 0;
}

