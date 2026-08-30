#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
	int val, id;
	long long mins;
	friend bool operator < (const node x, const node y){
		return x.mins > y.mins;
	}
};
priority_queue<node> q;
long long p[200005], s[200005];
int dp[200005];
int nowval = 1e9, nowid;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i], s[i] = s[i-1] + p[i];
	q.push(node{0, 0, 0});
	for (int i = 1; i <= n; i++){
		while (!q.empty() && q.top().mins <= s[i]){
			if (q.top().val < nowval){
				nowval = q.top().val;
				nowid = q.top().id;
			} else if (q.top().val == nowval && q.top().id > nowid){
				nowid = q.top().id;
			}
			q.pop();
		}
//		cout << nowid << ':';
		dp[i] = nowval + i - 1;
//		cout << dp[i] << '\n';
		q.push(node{dp[i] - i, i, s[i] + s[i] - s[nowid]});
	}
	cout << dp[n] << '\n';
	return 0;
}

