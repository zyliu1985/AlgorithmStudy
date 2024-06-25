#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

stack<int> st;
int a[100005], b[100005], d[300005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int cur = 0;
	bool zf = true;
	for (int i = 1; i <= n; i++){
		if (a[i]-b[i] >= 0 ^ zf){
			cur += 2;
			d[cur-1] = 0;
			d[cur] = abs(a[i]-b[i]);
		} else {
			cur++;
			d[cur] = abs(a[i]-b[i]);
		}
		if (a[i]-b[i] >= 0) zf = true;
		else zf = false;
	}
	int ans = 0;
	for (int i = 1; i <= cur; i++){
//		cout << d[i] << ' ' << ans << endl;
		if (st.empty() || d[i] >= st.top())
			st.push(d[i]);
		else{
			ans += st.top() - d[i];
			while (!st.empty() && st.top() > d[i]) st.pop();
			st.push(d[i]);
		}
	}
	ans += st.top();
	cout << ans << endl;
	return 0;
}