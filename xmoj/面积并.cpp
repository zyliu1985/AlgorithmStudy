#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int val, sum, l, r;
} tr[8 * 100005];
struct lin{
	int l, r, y, type;
} line[2 * 100005];
int X[2 * 100005], curx, curl;
void push_up(int x){
	if (tr[x].sum) tr[x].val = X[tr[x].r + 1] - X[tr[x].l];
	else if (tr[x].l == tr[x].r) tr[x].val = 0;
	else tr[x].val = tr[x * 2].val + tr[x * 2 + 1].val;
}
void update(int x, int L, int R, int c){
	if (X[tr[x].r + 1] <= L || X[tr[x].l] >= R) return;
	else if (X[tr[x].l] >= L && X[tr[x].r + 1] <= R){
		tr[x].sum += c;
		push_up(x);
		return;
	}
	update(x * 2, L, R, c);
	update(x * 2 + 1, L, R, c);
	push_up(x);
} 
void build(int x, int l, int r){
	tr[x].l = l, tr[x].r = r;
	if (l == r) return;
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid+1, r);
}
bool cmp(lin a, lin b){
	return a.y < b.y;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	build(1, 1, n * 2 - 1);
	for (int i = 1; i <= n; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		X[++curx] = x1;
		X[++curx] = x2;
		line[++curl] = {x1, x2, y1, 1};
		line[++curl] = {x1, x2, y2, -1};
	}
	sort(X+1, X+curx+1);
	sort(line+1, line+curl+1, cmp);
	long long ans = 0;
	for (int i = 1; i <= 2 * n; i++){
		ans += 1ll * tr[1].val * (line[i].y - line[i-1].y);
		cout << tr[1].val << '*' << (line[i].y - line[i-1].y) << '\n';
		update(1, line[i].l, line[i].r, line[i].type);
	}
	cout << ans << '\n';
	return 0;
}



