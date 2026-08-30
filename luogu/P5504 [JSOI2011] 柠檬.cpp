#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int c[100005];
long long cnt[100005];
int nc[10005];
long long dp[100005];
struct node{
	long long k, b;
};
deque<node> q[10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		cnt[i] = ++nc[c[i]];
	}
	q[c[1]].push_front(node{0, 0});
	for (int i = 1; i <= n; i++){
		long long x = cnt[i];
		node now, nxt;
		while (q[c[i]].size() > 1){
			now = q[c[i]].front();
			q[c[i]].pop_front();
			nxt = q[c[i]].front();
			if (-now.k * x + now.b > -nxt.k * x + nxt.b){
				q[c[i]].push_front(now);
				break;
			}
		}
		now = q[c[i]].front();
//		cout << "now: (" << now.k << ", " << now.b << ")\n";
		dp[i] = cnt[i] * cnt[i] * c[i] - now.k * x + now.b;
//		cout << dp[i] << '\n';
		if (i == n) break;
		long long nk = 2 * (cnt[i+1] - 1) * c[i+1];
		long long nb = (cnt[i+1] - 1) * (cnt[i+1] - 1) * c[i+1] + dp[i];
		while (q[c[i+1]].size() > 1){
			now = q[c[i+1]].front();
			q[c[i+1]].pop_front();
			nxt = q[c[i+1]].front();
			if ((now.b - nxt.b) * (__int128)1 * (nk - now.k) > (nb - now.b) * (__int128)1 * (now.k - nxt.k)){
				q[c[i+1]].push_front(now);
				break;
			}
		}
		q[c[i+1]].push_front(node{nk, nb});
	}
	cout << dp[n] << '\n';
	return 0;
}

