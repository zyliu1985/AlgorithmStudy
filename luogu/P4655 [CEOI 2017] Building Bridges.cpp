#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;

long long h[100005], sw[100005];
long long dp[100005];
struct node{
	long long k, b;
} templ[100005], tempr[100005];
int curl, curr;
deque<node> q;
bool cmp(node x, node y){
	if (x.k != y.k) return x.k < y.k;
	return x.b > y.b;
}
void solve(int l, int r){
	if (l == r) return;
	int mid = (l + r) / 2;
	solve(l, mid);
	curl = curr = 0;
	for (int i = l; i <= mid; i++)
		templ[++curl] = node{2 * h[i], dp[i] - sw[i] + h[i] * h[i]};
	for (int i = mid+1; i <= r; i++)
		tempr[++curr] = node{h[i], i};
	sort(templ+1, templ+curl+1, cmp);
	templ[0].k = -1;
//	cout << l << ',' << r << '\n'; 
//	for (int i = 1; i <= curl; i++)
//		cout << "(" << templ[i].k << ", " << templ[i].b << "), ";
//	cout << '\n'; 
	int nowid = 1; 
	for (int i = 1; i <= curl; i++){
		if (templ[nowid].k == templ[i-1].k){
			templ[i-1] = templ[nowid];
			i--, curl--;
		} else {
			templ[i] = templ[nowid];
		} 
		nowid++;
	}
//	for (int i = 1; i <= curl; i++)
//		cout << "(" << templ[i].k << ", " << templ[i].b << "), ";
//	cout << '\n'; 
	sort(tempr+1, tempr+curr+1, cmp);
	q.clear();
	for (int i = 1; i <= curl; i++){
		long long nk = templ[i].k;
		long long nb = templ[i].b;
		node now, nxt;
		while (q.size() > 1){
			now = q.front();
			q.pop_front();
			nxt = q.front();
			if ((now.b - nxt.b) * (__int128)1 * (nk - now.k) < (nb - now.b) * (__int128)1 * (now.k - nxt.k)){
				q.push_front(now);
				break;
			}
		}
		q.push_front(node{nk, nb});
	}
	for (int i = 1; i <= curr; i++){
		long long x = tempr[i].k;
		node now, nxt;
		while (q.size() > 1){
			now = q.back();
			q.pop_back();
			nxt = q.back();
			if (-now.k * x + now.b < -nxt.k * x + nxt.b){
				q.push_back(now);
				break;
			}
		}
		if (!q.empty()){
			now = q.back();
			dp[tempr[i].b] = min(dp[tempr[i].b], sw[tempr[i].b-1] + h[tempr[i].b] * h[tempr[i].b] - now.k * x + now.b);
		}
	}
	solve(mid+1, r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= n; i++){
		int w;
		cin >> w;
		sw[i] = sw[i-1] + w;
		dp[i] = 1e18;
	}
	dp[1] = 0;
	solve(1, n);
//	for (int i = 2; i <= n; i++){
//		long long x = h[i];
//		for (int j = 1; j < i; j++){
//			long long k = 2 * h[j];
//			long long b = f[j] - sw[j] + h[j] * h[j];
//			f[i] = min(f[i], -k * x + b);
//		}
//		f[i] += sw[i-1] + h[i] * h[i];
//	}
	cout << dp[n] << '\n';
	return 0;
}

