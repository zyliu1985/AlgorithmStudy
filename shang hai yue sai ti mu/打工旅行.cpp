#include <iostream>
#include <queue>
#include <stack>
#define int long long
using namespace std;

int a[300005], c[300005], s[300005];
struct node{
	int dis, x;
	friend bool operator < (const node x, const node y){
		return x.dis < y.dis;
	}
};
priority_queue<node> pq;
stack<int> st;
signed main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		s[i+1] = s[i] + c[i];
		pq.push({a[i], i});
	}
	int ans = 0, now = 1;
	int end = n+1;
	while (end != 1){
		if (pq.top().x < end){
			st.push(end);
			end = pq.top().x;
		}
		pq.pop();
	}
	int last = 0;
	while (!st.empty()){
//		cout << ans << ' ' << (s[st.top()] - s[now] - last) << endl;
		ans += (s[st.top()] - s[now] - last) / a[now] + ((s[st.top()] - s[now] - last) % a[now] > 0);
		last = (s[st.top()] - s[now] - last) % a[now];
		now = st.top();
		st.pop();
	}
	cout << ans << endl;
	return 0;
}