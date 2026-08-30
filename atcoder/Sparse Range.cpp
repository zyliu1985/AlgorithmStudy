#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int a[400005], pre[400005], nxt[400005];
struct node{
	int id, val;
	friend bool operator < (const node x, const node y){
		return x.val < y.val;
	}
};
set<node> st;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, d;
	cin >> n >> d;
	nxt[0] = n+1;
	pre[n+1] = 0;
	st.insert({0, -1100000000});
	st.insert({n+1, 2100000000});
	a[0] = -1100000000;
	a[n+1] = 2100000000;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 1;
	long long ans = 0;
	for (int r = 1; r <= n; r++){
		int rgt = (*st.lower_bound({r, a[r]})).id;
		int lft = pre[rgt];
		while (a[rgt] - a[r] < d || a[r] - a[lft] < d){
			if (!st.erase({l, a[l]})){
				return 0;
			}
			pre[nxt[l]] = pre[l];
			nxt[pre[l]] = nxt[l];
//			cout << "ers:" << l << '\n';
			l++;
			rgt = (*st.lower_bound({r, a[r]})).id;
			lft = pre[rgt];
		}
		ans += r - l + 1; 
//		cout << l << ' ' << r <<'\n';
		st.insert({r, a[r]});
		nxt[lft] = r;
		pre[rgt] = r;
		pre[r] = lft;
		nxt[r] = rgt;
//		cout << r - l + 1 << ' ' << st.size() << '\n';
	}
	cout << ans << '\n';
	return 0;
}

