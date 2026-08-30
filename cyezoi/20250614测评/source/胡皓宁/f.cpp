#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[3030], b[110];
vector<int> ls;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i], ls.push_back(a[i]);
	cin >> m;
	for (int i = 1; i <= m; i ++)
		cin >> b[i], ls.push_back(b[i]);
	sort(ls.begin(), ls.end(), greater<int>());
	n += m;
	ll answer = 0;
	for (int i = 0; i < (n + 1) / 2; i ++)
		answer += ls[i];
	cout << answer;
}
