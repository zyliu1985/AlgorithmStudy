#include <iostream>
#include <stack>
#define int long long
using namespace std;

int a[1000005];
bool flag[1000005];
stack<int> st;
signed main(){
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] < 0){
			if (i != 1 && flag[i-2]){
				a[i-1] = -a[i];
				a[i] = 0;
				flag[i-1] = true;
			} else {
				a[i+1] = -a[i];
				a[i] = 0;
				a[i+2] = 0;
				flag[i+1] = true;
				i += 2;
				n += 2;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if (st.empty()){
			st.push(a[i]);
			continue;
		}
		if (st.top() > a[i]) ans += st.top()-a[i];
		while (!st.empty() && st.top() > a[i]){
			st.pop();
		}
		st.push(a[i]);
	}
	if (st.empty()) return 0;
	ans += st.top();
	cout << ans << endl;
	return 0;
}