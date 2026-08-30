#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<char> mp[100005];
int sk[100005]; 
int h[100005], lft[100005], rgt[100005];
stack<int> st;
int n, m, k;
long long calc(){
	for (int i = 1; i <= m; i++){
		lft[i] = 0;
		rgt[i] = m + 1;
	}
	// rgt
	for (int i = 1; i <= m; i++){
		while (!st.empty() && h[st.top()] > h[i]){
			rgt[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) st.pop(); 
	// lft
	for (int i = m; i >= 1; i--){
		while (!st.empty() && h[st.top()] >= h[i]){
			lft[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) st.pop(); 
//	cout << "h:\n";
//	for (int i = 1; i <= m; i++)
//		cout << h[i] << ' ';
//	cout << '\n';
//	cout << "lf:\n";
//	for (int i = 1; i <= m; i++)
//		cout << lft[i] << ' ';
//	cout << '\n';
//	cout << "rg:\n";
//	for (int i = 1; i <= m; i++)
//		cout << rgt[i] << ' ';
//	cout << '\n';
	long long sum = 0;
	for (int i = 1; i <= m; i++)
		sum += h[i] * 1ll * (i - lft[i]) * (rgt[i] - i);
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		
	for (int i = 1; i <= n; i++){
		mp[i].resize(m+5);
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			if (mp[i][j] == '#'){
				h[j] = 0;
			} else {
				h[j]++;
			}
//		cout << calc() << '\n'; 
		ans += calc();
	}
	cout << ans << '\n';
	return 0;
}

