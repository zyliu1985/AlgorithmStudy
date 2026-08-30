#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct node{
	int x, id;
};
deque<node> q;
int from[100005];
int dp[100005];
string s;
void insert(node x){
	while (!q.empty() && (x.x < q.back().x || (x.x == q.back().x && x.id < q.back().id))) q.pop_back();
	q.push_back(x);
}
int n, m;
node query(int id){
	while (!q.empty() && q.front().id < id - m) q.pop_front();
	if (q.empty()) return node{-1, -1};
	return q.front();
}
int ans[100005], cur;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	dp[0] = 0;
	insert(node{0, 0});
	for (int i = 1; i <= n; i++){
		if (s[i] == '0'){
			node x = query(i);
			dp[i] = x.x;
			from[i] = x.id;
			if (dp[i] != -1) insert(node{dp[i], i});
		} else {
			dp[i] = -1;
		} 
	}
	if (dp[n] != -1){
		int now = n;
		while (now != 0){
			ans[++cur] = now - from[now];
			now = from[now];
		}
		for (int i = cur; i >= 1; i--)
			cout << ans[i] << ' ';
		cout << '\n'; 
	} else {
		cout << -1 << '\n';
	}
	return 0;
}

