#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int l[1005], g[1005], ans;
stack<int> st;
int main(){
	int n, cnt1 = 0, cnt2 = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		char c;
		int v;
		cin >> c >> v;
		if (c == 'L') l[++cnt1] = v;
		else g[++cnt2] = v;
	}
	sort(l+1, l+cnt1+1);
	sort(g+1, g+cnt2+1);
	for (int i = cnt1; i >= 1; i--)
		st.push(l[i]);
	ans = cnt1;
	for (int i = 1; i <= cnt2; i++){
		while (!st.empty() && g[i] > st.top())
			st.pop();
		ans = max(ans, int(st.size()) + i);
	}
	cout << n-ans << endl;
	return 0;
}