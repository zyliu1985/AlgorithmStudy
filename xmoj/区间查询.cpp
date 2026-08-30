#include <iostream>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;

struct query{
	int pos, x, nx, id;
	bool type;
} qu[200005];
bool cmp(query x, query y){
	if (x.pos != y.pos) return x.pos < y.pos;
	return x.type < y.type;
}
int a[100005], na[100005];
struct node{
	int val, id;
	bool type;
} temp[300005];
bool cmp0(node x, node y){
	return x.val < y.val;
}
int cur, num;
long long ans[100005];
long long tr1[300005];
int tr2[300005];
void insert(int x, int c){
	for (int i = x; i <= num; i += lowbit(i)){
		tr1[i] += c;
		tr2[i]++;
	}
}
long long query_sum(int x){
	long long re = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		re += tr1[i];
	return re;
}
int query_num(int x){
	int re = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		re += tr2[i];
	return re;
}
int main(){
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i], temp[++cur] = node{a[i], i, 0};
	for (int i = 1; i <= q; i++){
		int op, l, r, x;
		cin >> op >> l >> r >> x;
		qu[i*2-1] = query{l, x, 0, i, 0};
		temp[++cur] = node{x, i*2-1, 1};
		qu[i*2] = query{r, x, 0, i, 1};
		temp[++cur] = node{x, i*2, 1};
	}
	sort(temp+1, temp+cur+1, cmp0);
	for (int i = 1; i <= cur; i++){
		if (temp[i].val != temp[i-1].val)
			num++;
		if (!temp[i].type) na[temp[i].id] = num;
		else qu[temp[i].id].nx = num;
	}
	sort(qu+1, qu+q*2+1, cmp);
//	for (int i = 1; i <= n; i++)
//		cout << na[i] << ' ';
//	cout << '\n';
//	for (int i = 1; i <= q * 2; i++)
//		cout << qu[i].pos << ',' << qu[i].nx << '\n';
	for (int i = 1; i <= q * 2; i++){
		for (int j = qu[i-1].pos + 1; j <= qu[i].pos-1; j++)
			insert(num - na[j] + 1, a[j]);
		if (!qu[i].type){
			ans[qu[i].id] -= query_sum(num - qu[i].nx + 1) - qu[i].x * 1ll * query_num(num - qu[i].nx + 1);
//			cout << "ans[" << qu[i].id << "] minus " << query_sum(qu[i].nx) << ',' << query_num(qu[i].nx) << '\n';
			if (qu[i+1].pos != qu[i].pos) insert(num - na[qu[i].pos] + 1, a[qu[i].pos]);
		} else {
			if (qu[i-1].pos != qu[i].pos || qu[i-1].type == 0) insert(num - na[qu[i].pos] + 1, a[qu[i].pos]);
			ans[qu[i].id] += query_sum(num - qu[i].nx + 1) - qu[i].x * 1ll * query_num(num - qu[i].nx + 1);
//			cout << "ans[" << qu[i].id << "] add " << query_sum(qu[i].nx) << ',' << query_num(qu[i].nx) << '\n';
		}
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n';
	return 0;
}

