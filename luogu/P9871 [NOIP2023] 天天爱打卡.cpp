#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int val, type, id, w;
} s[300005];
bool cmp1(node x, node y){
	return x.val < y.val;
}
struct chal{
	int l, r, lt, w;
} a[100005];
bool cmp2(chal x, chal y){
	return x.r < y.r;
}
int n, m, k, d;
long long dp[100005];
int org[300005];
long long tr[4 * 300005], lz[4 * 300005];
int cur;
void push_up(int x){
	tr[x] = max(tr[x*2], tr[x*2+1]);
}
void push_down(int x){
	if (lz[x]){
		tr[x*2] += lz[x];
		tr[x*2+1] += lz[x];
		lz[x*2] += lz[x];
		lz[x*2+1] += lz[x];
		lz[x] = 0;
	}
}
void init(int x, int nl, int nr){
	lz[x] = 0;
	if (nl == nr){
		tr[x] = org[nl] * 1ll * d;
		return;
	}
	int mid = (nl + nr) / 2;
	init(x * 2, nl, mid), init(x * 2 + 1, mid+1, nr);
	push_up(x);
}
void add(int l, int r, long long c, int x = 1, int nl = 1, int nr = cur){
	if (nr < l || r < nl) return;
	if (l <= nl && nr <= r){
		tr[x] += c;
		lz[x] += c;
		return;
	}
	int mid = (nl + nr) / 2;
	push_down(x);
	add(l, r, c, x*2, nl, mid);
	add(l, r, c, x*2+1, mid+1, nr);
	push_up(x);
}
long long query(int l, int r, int x = 1, int nl = 1, int nr = cur){
	if (nr < l || r < nl) return 0;
	if (l <= nl && nr <= r) return tr[x];
	int mid = (nl + nr) / 2;
	push_down(x);
	return max(query(l, r, x*2, nl, mid), query(l, r, x*2+1, mid+1, nr));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--){
		cur = 0;
		cin >> n >> m >> k >> d;
		for (int i = 1; i <= m; i++){
			int x, y, w;
			cin >> x >> y >> w;
			s[3*i-2].val = x - y + 1;
			s[3*i-1].val = x;
			s[3*i].val = x - k + 1;
			s[3*i-2].type = 0;
			s[3*i-1].type = 1;
			s[3*i].type = 2;
			s[3*i-2].id = s[3*i-1].id = s[3*i].id = i;
			s[3*i-2].w = s[3*i-1].w = w;
		}
		sort(s+1, s+3*m+1, cmp1);
		int lst = -1e9;
		for (int i = 1; i <= 3*m; i++){
//			cout << s[i].val << ';' << s[i].id << ';' << s[i].type << ';' << s[i].w <<'\n';
			if (s[i].val == lst){
				lst = s[i].val;
				s[i].val = cur;
			} else {
				lst = s[i].val;
				org[cur+1] = s[i].val;
				s[i].val = ++cur;
			}
			if (s[i].type == 2){
				a[s[i].id].lt = s[i].val;
			} else if (s[i].type == 1){
				a[s[i].id].r = s[i].val;
				a[s[i].id].w = s[i].w;
			} else {
				a[s[i].id].l = s[i].val;
				a[s[i].id].w = s[i].w;
			}
		}
		sort(a+1, a+m+1, cmp2);
		init(1, 1, cur);
//		for (int i = 1; i <= cur; i++)
//			tr[i] = org[i] * 1ll * d;
		for (int i = 1; i <= m; i++){
//			cout << a[i].l << ',' << a[i].r << ',' << a[i].lt << ',' << a[i].w << ':'; 
			add(a[i].lt, a[i].l, a[i].w);
//			dp[i] = dp[i-1];
			dp[i] = max(dp[i-1], query(a[i].lt, a[i].r) - d - org[a[i].r] * 1ll * d);
//			cout << dp[i] << '\n';
			if (i == m) continue;
			int begin;
			if (org[a[i].r] + 2 > org[a[i].r+1]) begin = a[i].r+2;
			else begin = a[i].r+1;
			int end;
			if (org[a[i+1].r] + 1 >= org[a[i+1].r+1]) end = a[i+1].r+1;
			else end = a[i+1].r;
			add(begin, end, dp[i]);
//			for (int j = begin; j <= end; j++)
//				tr[j] += dp[i];
		}
		cout << dp[m] << '\n';
	} 
	return 0;
}

