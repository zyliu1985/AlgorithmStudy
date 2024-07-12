#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string s;
int f[500005], dp[500005];
long long sum[500005];
vector<int> ch[500005];
stack<int> st;
void dfs(int x){
	if (s[x] == '('){
		st.push(x);
		sum[x] = sum[f[x]];
		for (int i = 0; i < ch[x].size(); i++)
			dfs(ch[x][i]);
		st.pop();
	}
	else if (s[x] == ')' && !st.empty()){
		int y = st.top();
		dp[x] = dp[f[y]] + 1;
		sum[x] = sum[f[x]] + dp[x];
		st.pop();
		for (int i = 0; i < ch[x].size(); i++)
			dfs(ch[x][i]);
		st.push(y);
	} else {
		sum[x] = sum[f[x]];
		for (int i = 0; i < ch[x].size(); i++)
			dfs(ch[x][i]);
	}
}
int main(){
	int n;
	cin >> n;
	cin >> s;
	s = ' ' + s;
	for (int i = 2; i <= n; i++){
		cin >> f[i];
		ch[f[i]].push_back(i);
	}
	dfs(1);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans = ans ^ (sum[i] * i);
	cout << ans << endl;
	return 0;
}