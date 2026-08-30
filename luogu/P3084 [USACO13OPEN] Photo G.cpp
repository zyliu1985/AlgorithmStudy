#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

struct node{
	int l, r;
} a[100005];
bool cmp(node x, node y){
	return x.r < y.r;
}
int dp[200005];
int lt[100005], rt[100005];
struct vid{
	int v, id;
};
deque<vid> q;
void insert(vid x){
	while (!q.empty() && x.v >= q.back().v) q.pop_back();
	q.push_back(x);
}
vid query(int l){
	while (!q.empty() && q.front().id < l) q.pop_front();
	if (q.empty()) return vid{-2, -2};
	return q.front();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i].l >> a[i].r;
	a[m+1].l = 1e9, a[m+1].r = 1e9;
	sort(a+1, a+m+1, cmp); 
	for (int i = 1; i <= m; i++)
		lt[i] = max(lt[i-1], a[i].l);
	rt[m+1] = 1e9;
	for (int i = m; i >= 1; i--)
		rt[i] = min(rt[i+1], a[i].l);
	
//	for (int i = 1; i <= m; i++)
//		cout << lt[i] << ' ';
//	cout << '\n';
//	for (int i = 1; i <= m; i++)
//		cout << rt[i] << ' ';
//	cout << '\n'; 
	dp[0] = 0;
	int pos = 1, nr;
	nr = -1;
	insert(vid{0, 0});
	for (int i = 1; i <= n; i++){
		while (a[pos].r < i) pos++;
		for (int j = nr+1; j <= min(i-1, rt[pos]-1); j++)
			if (dp[j] != -1) insert(vid{dp[j], j});
		nr = min(i-1, rt[pos]-1);
//		cout << i << ':' << lt[pos-1] << ',' << nr-1 << '\n';
		dp[i] = query(lt[pos-1]).v + 1;
//		cout << i << ';' << dp[i] << '\n'; 
	}
	int ans = -1;
	for (int i = a[m].l; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n'; 
	return 0;
}

