#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct node{
	int val, sum, duan, l, r;
	bool lsta, rsta;
} tr[8 * 5005];
struct lin{
	int l, r, y, type;
} line[2 * 5005];
int X[2 * 5005], curx, curl;
void push_up(int x){
	if (tr[x].sum){
		tr[x].val = X[tr[x].r + 1] - X[tr[x].l];
		tr[x].duan = 2;
		tr[x].lsta = tr[x].rsta = 1;
	} else if (tr[x].l == tr[x].r) {
		tr[x].val = 0;
		tr[x].duan = 0;
		tr[x].lsta = tr[x].rsta = 0;
	} else {
		tr[x].val = tr[x * 2].val + tr[x * 2 + 1].val;
		tr[x].duan = tr[x * 2].duan + tr[x * 2 + 1].duan - (tr[x * 2].rsta && tr[x * 2 + 1].lsta) * 2;
		tr[x].lsta = tr[x * 2].lsta;
		tr[x].rsta = tr[x * 2 + 1].rsta;
	}
}
void update(int x, int L, int R, int c){
//	cout << x;
	if (X[tr[x].r + 1] <= L || X[tr[x].l] >= R){
//		cout << "*\n";
		return;
	}
	else if (X[tr[x].l] >= L && X[tr[x].r + 1] <= R){
//		cout << "**\n";
		tr[x].sum += c;
		push_up(x);
		return;
	}
//	cout << '\n';
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
	int lastval = 0;
	for (int i = 1; i <= 2 * n; i++){
		update(1, line[i].l, line[i].r, line[i].type);
		ans += abs(tr[1].val - lastval) + (line[i+1].y - line[i].y) * tr[1].duan * (i != 2 * n);
//		cout << "l:" << line[i].l << " r:" << line[i].r << " y:" << line[i].y << " type:" << line[i].type << '\n';
//		for (int j = 1; j <= 4 * n; j++)
//			if (tr[j].l != 0) cout << "tr[" << j << "]: l:" << X[tr[j].l] << "   r:" << X[tr[j].r + 1] << "   duan:" << tr[j].duan << "   lsta:" << tr[j].lsta << "   rsta:" << tr[j].rsta << '\n';
//		cout << "heng:" << abs(tr[1].val - lastval) << "  last:" << lastval << "  now:" << tr[1].val << "   | shu*:" << (line[i+1].y - line[i].y) * tr[1].duan * (i != 2 * n) << "  num:" << tr[1].duan << '\n';
		lastval = tr[1].val;
	}
	cout << ans << '\n';
	return 0;
}



