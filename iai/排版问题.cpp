#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int a[200005];
long long dp[200005];
int s[200005];
struct node{
	long long k, b;
};
deque<node> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
		cin >> a[i], s[i] = s[i-1] + a[i];
	q.push_front(node{0, 0});
	for (int i = 1; i <= n; i++){
//		cout << "----------" << i << "----------\n";
		int x = s[i];
//		cout << "x:" << x << '\n'; 
//		cout << "q:" << '\n';
//		for (int j = 0; j < q.size(); j++)
//			cout << "(" << q[j].k << ',' << q[j].b << "), ";
//		cout << '\n';
		node now, nxt;
		while (q.size() > 1){
			now = q.back();
			q.pop_back();
			nxt = q.back();
			if (-now.k * x + now.b < -nxt.k * x + nxt.b){
//				cout << -nxt.k * x + nxt.b << '\n';
				q.push_back(now);
				break;
			}
		}
		now = q.back();
		dp[i] = s[i] * 1ll * s[i] - 2 * l * 1ll * s[i] + l * 1ll * l - now.k * x + now.b;
//		cout << "dp: " << dp[i] << '\n';
		long long nk = 2 * s[i];
		long long nb = dp[i] + 2 * l * 1ll * s[i] + s[i] * 1ll * s[i];
		while (q.size() > 1){
			now = q.front();
			q.pop_front();
			nxt = q.front();
			if ((now.b - nxt.b) * 1ll * (nk - now.k) < (nb - now.b) * 1ll * (now.k - nxt.k)){
				q.push_front(now);
				break;
			}
		}
		q.push_front(node{nk, nb});
	}
	cout << dp[n] << '\n';
	return 0;
}

