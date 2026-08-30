#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7; 
struct node{
	int val, id;
};
struct deq{
	int l, r;
	node val[100005];
	deq(){
		l = 1;
		r = 0;
	}
	bool empty(){
		return l > r;
	}
	void clear(){
		l = 1, r = 0;
	}
	void push_front(node x){
		val[++r] = x;
	} 
	void pop_front(){
		r--;
	} 
	void pop_back(){
		l++;
	} 
	node front(){
		return val[r];
	}
	node back(){
		return val[l];
	}
} minn, maxn;
int h[100005], ans[100005], n;
void ps(int x){
	int mina = min(h[x], h[x+1]), maxa = max(h[x], h[x+1]);
	// minn 
	while (!minn.empty() && minn.front().val <= mina) minn.pop_front();
	minn.push_front({mina, x});
	// maxn;
	while (!maxn.empty() && maxn.front().val >= maxa) maxn.pop_front();
	maxn.push_front({maxa, x});
}
int st[25][100005], Log2[100005];
void build_st(){
	int m = n - 1;
	Log2[0] = -1;
	for (int i = 1; i <= m; i++)
		Log2[i] = Log2[i / 2] + 1;
	for (int i = 1; i <= m; i++)
		st[0][i] = i - ans[i] + 2;
	for (int i = 1; i <= Log2[m]; i++)
		for (int j = 1; j <= m - (1 << i) + 1; j++)
			st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i-1))]);
}
long long quary(int l, int r){
	int k = r - l + 1;
	return max(st[Log2[k]][l], st[Log2[k]][r - (1 << Log2[k]) + 1]);
}
int main(){
//	freopen("D.in", "r", stdin);;
//	freopen("D.out", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
		int q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++)
			cin >> h[i];
    	minn.clear();
    	maxn.clear();
		for (long long l = 1, r = 1; r < n; r++){
			ps(r);
			while (!minn.empty() && !maxn.empty() && minn.back().val >= maxn.back().val){
				if (l == minn.back().id) minn.pop_back();
				if (l == maxn.back().id) maxn.pop_back();
				l++;
			}
			ans[r] = l; 
		}
//		for (int i = 1; i < n; i++)
//			cout << ans[i] << ' ';
//		cout << '\n';
		build_st();
		long long nans = 0; 
		for (int i = 1; i <= q; i++){
			int x, y;
			cin >> x >> y;
			int t = lower_bound(ans+1, ans+n, x) - ans - 1;
			if (t < y - 1){
//				cout << "**" << max(quary(t + 1, y - 1), (long long)(t - x + 2)) << '\n'; 
				nans = (nans + (max(quary(t + 1, y - 1), (long long)(t - x + 2)) * i) % mod) % mod;
			}
			else{
//				cout << "//" << (long long)(y - x + 1) << '\n'; 
				nans = (nans + (long long)(y - x + 2) * i % mod) % mod;
			}
		}
		cout << nans << '\n';
	}
	return 0;
}


