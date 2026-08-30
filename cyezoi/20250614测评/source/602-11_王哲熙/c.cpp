#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
using i64 = long long;
const int MAXN = 5005;
int h[MAXN], s[MAXN][MAXN], sum[MAXN][MAXN];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
		s[i - 1][i] = (h[i] - h[i - 1]);
	}
	
	for (int i = 1; i <= n - 2; ++i)
		for (int j = i + 2; j <= n; ++j) s[i][j] = s[j - 1][j] + s[i][j - 1];
	
	for (int i = 1; i < n; ++i) sum[2][i] = abs(s[i][i + 1]);
	for (int i = 1; i < n - 1; ++i) sum[3][i] = abs(s[i][i + 2]);
	
	for (int len = 1; len <= n; ++len)
		for (int st = 1; st <= n - len + 1; ++st)
			sum[len][st] = sum[len - 2][st + 1] + abs(s[st][st + len - 1]);
	
	for (int len = 1; len <= n; ++len) {
		i64 ans = LLONG_MAX;
		for (int st = 1; st <= n - len + 1; ++st)
			if (sum[len][st] < ans) ans = sum[len][st];
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}
