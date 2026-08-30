#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct node{
	long long k, b;
};
deque<node> q;
long long x[1000005], sump[1000005], c[1000005], sumpx[1000005];
__int128 dp[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		long long p;
		cin >> x[i] >> p >> c[i];
		sump[i] = sump[i-1] + p;
		sumpx[i] = sumpx[i-1] + x[i] * p;
	}
	dp[0] = 0;
	q.push_front(node{0, 0});
	for (int i = 1; i <= n; i++){
		long long nx = x[i];
		node now, nxt;
		while (q.size() > 1){
			now = q.back();
			q.pop_back();
			nxt = q.back();
			if (-now.k * nx + now.b < -nxt.k * nx + nxt.b){
				q.push_back(now);
				break;
			}
		}
		now = q.back();
//		cout << "now: (" << now.k << ", " << now.b << ")\n"; 
		dp[i] = -now.k * nx + now.b + c[i] + sump[i-1] * x[i] - sumpx[i-1];
//		cout << i << ':' << dp[i] << '\n'; 
		if (sump[i] == sump[i-1]) dp[i] = min(dp[i], dp[i-1]);
		long long nk = sump[i];
		long long nb = sumpx[i] + dp[i];
//		cout << "(" << nk << ", " << nb << ")\n"; 
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
	cout << (long long)(dp[n]) << '\n';
	return 0;
}

