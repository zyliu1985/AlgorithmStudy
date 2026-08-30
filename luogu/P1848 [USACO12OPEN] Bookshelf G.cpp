#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
using namespace std;

int h[100005], w[100005];
long long sw[100005];
long long dp[100005];
deque<pair<int, int> > q;
stack<pair<long long, long long> > lft, rgt;
void push_lft(long long x){
	if (lft.empty()) lft.push(make_pair(x, x));
	else lft.push(make_pair(x, min(x, lft.top().second)));
}
void push_rgt(long long x){
	if (rgt.empty()) rgt.push(make_pair(x, x));
	else rgt.push(make_pair(x, min(x, rgt.top().second)));
}
void rebal(){
	if (lft.empty() && rgt.empty()) exit(1);
	stack<long long> temp;
	while (!temp.empty()) temp.pop();
	if (lft.empty()){
		for (int i = 1; i <= rgt.size() / 2; i++)
			temp.push(rgt.top().first), rgt.pop();
		while (!rgt.empty()) push_lft(rgt.top().first), rgt.pop();
		while (!temp.empty()) push_rgt(temp.top()), temp.pop();
	} else {
		for (int i = 1; i <= lft.size() / 2; i++)
			temp.push(lft.top().first), lft.pop();
		while (!lft.empty()) push_rgt(lft.top().first), lft.pop();
		while (!temp.empty()) push_lft(temp.top()), temp.pop();
	}
}
void pop_lft(){
	if (lft.empty()){
		rebal();
		lft.pop();
	} else lft.pop();
}
void pop_rgt(){
	if (rgt.empty()){
		rebal();
		rgt.pop();
	} else rgt.pop();
}
long long query_min(){
	long long re = 1e18;
	if (!lft.empty()) re = min(re, lft.top().second);
	if (!rgt.empty()) re = min(re, rgt.top().second);
	return re;
}
deque<pair<int, int> > maxh;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, len;
	cin >> n >> len; 
	for (int i = 1; i <= n; i++)
		cin >> h[i] >> w[i], sw[i] = sw[i-1] + w[i];
	dp[0] = 0;
	push_rgt(0);
	q.push_back(make_pair(0, 0));
	int l = 0;
//	 ×ªÒÆµãÊÇl 
	for (int i = 1; i <= n; i++){
		while (sw[i] - sw[l] > len) l++;
		while (!maxh.empty() && maxh.front().second <= l) maxh.pop_front();
		while (!maxh.empty() && h[i] >= maxh.back().first) maxh.pop_back();
		maxh.push_back(make_pair(h[i], i));
		int lst = -1;
		while (!q.empty() && q.front().second <= l) q.pop_front(), pop_lft();
		while (!q.empty() && q.back().first <= h[i]) lst = q.back().second, q.pop_back(), pop_rgt();
		if (lst != -1) q.push_back(make_pair(h[i], lst)), push_rgt(dp[lst] + h[i]);
		dp[i] = min(query_min(), dp[l] + maxh.front().first);
		q.push_back(make_pair(0, i)), push_rgt(dp[i]);
		
	}
	cout << dp[n] << '\n';
	return 0;
}

