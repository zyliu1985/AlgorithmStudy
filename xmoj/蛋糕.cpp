#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> st;
int fst10[15];
struct node{
	int id, vl;
} t[250005];
int d[250005], ans[250005];
int inf10[250005];
bool cmp(node x, node y){
	return x.vl > y.vl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> d[i], t[i].vl = d[i], t[i].id = i;
	}
	sort(t+1, t+n+1, cmp);
	for (int i = 1; i <= min(n, 10); i++)
		fst10[i] = t[i].id, inf10[t[i].id] = i;
	d[0] = d[n+1] = 1e9;
	st.push(0);
	for (int i = 1; i <= n; i++){
		while (!st.empty() && d[st.top()] < d[i]) st.pop();
		if (i > k) ans[i] = st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	st.push(n+1);
	for (int i = n; i >= 1; i--){
		while (!st.empty() && d[st.top()] < d[i]) st.pop();
		if (i < k) ans[i] = st.top();
		st.push(i);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
	int q;
	cin >> q;
	while (q--){
		char c;
		cin >> c;
		if (c == 'F'){
			int x;
			cin >> x;
			cout << abs(ans[x] - x - 1) << '\n';
		} else {
			int x, e;
			cin >> x >> e;
			
		}
	} 
	return 0;
}

