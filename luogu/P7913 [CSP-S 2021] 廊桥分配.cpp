#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> st;
int nxt[100005], pre[100005];
int brg[100005];
int ans1[100005], ans2[100005];
struct node{
	int val, id;
	bool type;
} a[200005], b[200005];
bool cmp(node x, node y){
	return x.val < y.val;
}
void setup(int x){
	st.clear();
	for (int i = 0; i <= x+1; i++)
		st.insert(i);
	nxt[0] = 1;
	for (int i = 1; i <= x; i++){
		pre[i] = i-1;
		nxt[i] = i+1;
		brg[i] = 0;
	}
	pre[x+1] = x;
}
int ins(){
	int pos = nxt[0];
	nxt[0] = nxt[pos];
	pre[nxt[pos]] = 0;
	st.erase(pos);
	return pos;
}
void del(int x){
	int nt = *st.lower_bound(x);
	pre[x] = pre[nt];
	nxt[x] = nt;
	nxt[pre[x]] = x;
	pre[nt] = x;
	st.insert(x);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= m1; i++){
		cin >> a[i*2-1].val >> a[i*2].val;
		a[i*2-1].type = 1;
		a[i*2].type = 0;
		a[i*2-1].id = a[i*2].id = i;
	}
	for (int i = 1; i <= m2; i++){
		cin >> b[i*2-1].val >> b[i*2].val;
		b[i*2-1].type = 1;
		b[i*2].type = 0;
		b[i*2-1].id = b[i*2].id = i;
	}
	sort(a+1, a+2*m1+1, cmp);
	sort(b+1, b+2*m2+1, cmp);
	setup(m1);
	for (int i = 1; i <= 2*m1; i++){
		if (a[i].type){
			brg[a[i].id] = ins();
			ans1[brg[a[i].id]]++;
		} else {
			del(brg[a[i].id]);
		}
	}
	for (int i = 1; i <= n; i++)
		ans1[i] += ans1[i-1];
	setup(m2);
	for (int i = 1; i <= 2*m2; i++){
		if (b[i].type){
			brg[b[i].id] = ins();
			ans2[brg[b[i].id]]++;
		} else {
			del(brg[b[i].id]);
		}
	}
	for (int i = 1; i <= n; i++)
		ans2[i] += ans2[i-1];
	int ans = 0;
	for (int i = 0; i <= n; i++){
		ans = max(ans, ans1[i] + ans2[n-i]);
	}
	cout << ans << '\n';
	return 0;
}

