#include <iostream>
#include <algorithm>
#include <vector>
#define lowbit(x) (x&-x)
using namespace std;

int n, rt;
vector<int> v[300005];
int sz[300005], mxsz[300005];

long long tr1[300005], tr2[300005];
void add1(int x, int c){
	if (x <= 0) return;
	for (int i = x; i <= n; i += lowbit(i))
		tr1[i] += c;
}
long long query1(int l, int r){
	long long re1, re2;
	re1 = re2 = 0;
	for (int i = l-1; i >= 1; i -= lowbit(i))
		re1 += tr1[i];
	for (int i = r; i >= 1; i -= lowbit(i))
		re2 += tr1[i];
	return re2 - re1;
}
void add2(int x, int c){
	if (x <= 0) return;
	for (int i = x; i <= n; i += lowbit(i))
		tr2[i] += c;
}
long long query2(int l, int r){
	long long re1, re2;
	re1 = re2 = 0;
	for (int i = l-1; i >= 1; i -= lowbit(i))
		re1 += tr2[i];
	for (int i = r; i >= 1; i -= lowbit(i))
		re2 += tr2[i];
	return re2 - re1;
}

bool flag[300005];
int mxid, mxid2;
long long ans;
void init(int x, int fa){
	sz[x] = 1;
	mxsz[x] = 0;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		init(v[x][i], x);
		sz[x] += sz[v[x][i]];
		mxsz[x] = max(mxsz[x], sz[v[x][i]]);
	}
}
void dfs(int x, int fa){
	add1(sz[x], -1);
	add1(n - sz[x], 1);
	add2(sz[x], 1);
	if (x != rt){
		ans += query1(n - 2 * sz[x], n - 2 * mxsz[x]) * x;
//		cout << x << ": (1)+" << query1(n - 2 * sz[x], n - 2 * mxsz[x]) * x << '\n';
		ans += query2(n - 2 * sz[x], n - 2 * mxsz[x]) * x;
//		cout << x << ": (2)+" << query2(n - 2 * sz[x], n - 2 * mxsz[x]) * x << '\n';
		if (flag[fa] || flag[x]){
			flag[x] = 1;
			ans += (sz[x] <= (n - 2 * sz[mxid2])) * rt;
		} else {
			ans += (sz[x] <= (n - 2 * sz[mxid])) * rt;
		}
	}
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		dfs(v[x][i], x); 
	}
	if (x != rt){
		ans -= query2(n - 2 * sz[x], n - 2 * mxsz[x]) * x;
//		cout << x << ": -" << query2(n - 2 * sz[x], n - 2 * mxsz[x]) * x << '\n';
	}
	add1(sz[x], 1);
	add1(n - sz[x], -1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			v[i].clear(), tr1[i] = tr2[i] = 0, flag[i] = false;
		for (int i = 1; i < n; i++){
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		init(1, 0);
		rt = -1;
		for (int i = 1; i <= n; i++)
			if (2 * mxsz[i] <= n && 2 * (n - sz[i]) <= n){
				rt = i;
				break;
			}
		init(rt, 0);
		mxid = mxid2 = 0;
		for (int i = 0; i < v[rt].size(); i++){
			if (sz[v[rt][i]] > sz[mxid]){
				mxid2 = mxid;
				mxid = v[rt][i];
			} else if (sz[v[rt][i]] > sz[mxid2])
				mxid2 = v[rt][i];
		}
		flag[mxid] = 1;
		for (int i = 1; i <= n; i++)
			add1(sz[i], 1);
		dfs(rt, 0);
		cout << ans << '\n';
	}
	return 0;
}

