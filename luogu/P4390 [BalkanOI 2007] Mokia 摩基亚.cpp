#include <iostream>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;

int w;
struct ask{
	int x, y, a;
	int type, id;
} q[200005], t[200005];
bool cmp(ask x, ask y){
	if (x.x != y.x) return x.x < y.x;
	if (x.y != y.y) return x.y < y.y;
	return y.type;
}
int cur;
int q2cur;
int tcur;
long long ans[10005];
long long tr[2000005];
void insert(int x, int c){
	for (int i = x; i <= w; i += lowbit(i))
		tr[i] += c;
}
void del(int x, int c){
	for (int i = x; i <= w; i += lowbit(i))
		tr[i] -= c;
}
long long query(int x){
	long long re = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		re += tr[i];
	return re;
}
void solve(int l, int r){
	if (l == r) return;
//	cout << "l:" << l << "  r:" << r << '\n';
	int mid = (l + r) / 2;
	solve(l, mid), solve(mid+1, r);
	tcur = 0;
	for (int i = l; i <= r; i++)
		if ((q[i].type != 0) ^ (i <= mid)) t[++tcur] = q[i];
//	cout << "tcur: " << tcur << '\n'; 
	sort(t+1, t+tcur+1, cmp);
	for (int i = 1; i <= tcur; i++)
		if (!t[i].type){
			insert(t[i].y, t[i].a);
		} else {
//			cout << "(" << t[i].x << ',' << t[i].y << "): " << t[i].id << ':' << query(t[i].y) * t[i].type << '\n';
			ans[t[i].id] += query(t[i].y) * t[i].type;
		}
	for (int i = 1; i <= tcur; i++)
		if (!t[i].type){
			del(t[i].y, t[i].a);
		}
//	cout << "return\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int op;
	cin >> op;
	while (op != 3){
		if (op == 0){
			cin >> w;
		} else if (op == 1){
			cur++;
			cin >> q[cur].x >> q[cur].y >> q[cur].a;
			q[cur].type = 0;
		} else if (op == 2){
			q2cur++;
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			q[++cur] = {x2, y2, 0, 1, q2cur};
			q[++cur] = {x2, y1-1, 0, -1, q2cur};
			q[++cur] = {x1-1, y2, 0, -1, q2cur};
			q[++cur] = {x1-1, y1-1, 0, 1, q2cur};
		}
		cin >> op;
	}
	solve(1, cur);
	for (int i = 1; i <= q2cur; i++)
		cout << ans[i] << '\n';
	return 0;
}

