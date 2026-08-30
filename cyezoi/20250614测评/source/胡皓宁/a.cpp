#include <bits/stdc++.h>
using namespace std;
int n, cnt[10];
vector<int> answer;
string ls[100010];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> ls[i];
	int maxn = 0;
	for (int i = 1; i <= 5; i ++) {
		for (int j = 1; j <= n; j ++)
			cnt[i] += (ls[j][i - 1] == 'Y');
		maxn = max(maxn, cnt[i]);
	}
	for (int i = 1; i <= 5; i ++) {
		if (cnt[i] == maxn)
			answer.push_back(i);
	}
	n = answer.size();
	for (int i = 0; i < n - 1; i ++)
		cout << answer[i] << ',';
	cout << answer[n - 1];
}
