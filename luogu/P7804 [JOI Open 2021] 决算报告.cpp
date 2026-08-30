#include <iostream>
#include <algorithm>
#include <set>
#define lowbit(x) (x&-x)
using namespace std;

int n, d;
set<int> st;
namespace bcj{
	int fa[300005];
	int find(int x){
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int x, int y){
		int zx = find(x), zy = find(y);
		if (zx != zy){
			fa[zx] = zy;
		}
	}
}
namespace xds{
	int tr[4 * 300005], l[4 * 300005], r[4 * 300005];
	void push_up(int x){
		tr[x] = max(tr[x * 2], tr[x * 2 + 1]);
	}
	void init(int nl = 1, int nr = n, int now = 1){
		l[now] = nl, r[now] = nr;
		if (l[now] == r[now]) return;
		int mid = (nl + nr) / 2;
		init(nl, mid, now * 2);
		init(mid+1, nr, now * 2 + 1);
		push_up(now);
	}
	void add(int pos, int x, int now = 1){
		if (l[now] == r[now]){
			tr[now] += x;
			return;
		}
		int mid = (l[now] + r[now]) / 2;
		if (pos <= mid) add(pos, x, now * 2);
		else add(pos, x, now * 2 + 1);
		push_up(now);
	}
	int quary(int nl, int nr, int now = 1){
		if (r[now] < nl || nr < l[now]) return 0;
		if (nl <= l[now] && r[now] <= nr) return tr[now];
		return max(quary(nl, nr, now * 2), quary(nl, nr, now * 2 + 1));
	}
}
int a[300005], dp[300005];
struct node{
	int id, x;
} s[300005];
bool cmp(node p, node q){
	if (p.x != q.x) return p.x < q.x;
	return p.id > q.id;
}
int main(){
//	ios::sync_with_stdio(0);
//    cin.tie(0);
	cin >> n >> d;
	xds::init(); 
	for (int i = 1; i <= n; i++)
		bcj::fa[i] = i;
	for (int i = 1; i <= n; i++)
		cin >> a[i], s[i].x = a[i], s[i].id = i;
	sort(s+1, s+n+1, cmp);
	for (int i = 1; i <= n; i++){
		int now = s[i].id;
		auto place = st.lower_bound(now);
//		cout << "______________\n" << (place == st.end());
		int pre = -1e9, nxt = 1e9;
		if (place != st.end()) nxt = *place;
		if (place != st.begin()++) pre = *(--place);
//		if (place == st.lower_bound(now)--){
//			cout << "WRONR!";
//			return 0;
//		}
//		cout << "i:" << now << "  pre:" << pre << "  nxt:" << nxt << '\n'; 
		if (now - pre <= d) bcj::merge(now, pre);
		if (nxt - now <= d) bcj::merge(nxt, now);
//		cout << bcj::find(now) << '\n';
		dp[now] = xds::quary(bcj::find(now), now) + 1;
		st.insert(now);
		xds::add(now, dp[now]);
	}
//	for (int i = 1; i <= n; i++)
//		cout << dp[i] << ' ';
//	cout << '\n';
	cout << xds::quary(1, n) << '\n';
	return 0;
}



