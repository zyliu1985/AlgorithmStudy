#include <bits/stdc++.h>
using namespace std;
const int maxi = 1e9;
int n, h[5050], prefix[5050];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> h[i];
	if (n <= 300) {
		for (int i = 1; i <= n; i ++) {
			int answer = maxi;
			for (int l = 1; l + i - 1 <= n; l ++) {
				int r = l + i - 1;
				int result = 0;
				for (int i = 0; i <= (r - l) / 2; i ++)
					result += abs(h[l + i] - h[r - i]);
				answer = min(answer, result);
			}
			cout << answer << " ";
		}
		return 0;
	}
	sort(h + 1, h + n + 1);
	for (int i = 1; i <= n; i ++)
		prefix[i] = prefix[i - 1] + h[i];
	for (int i = 1; i <= n; i ++) {
		int answer = maxi;
		for (int l = 1; l + i - 1 <= n; l ++) {
			int r = l + i - 1;
			answer = min(answer, (prefix[r] - prefix[r - (r - l) / 2 - 1]) - (prefix[l + (r - l) / 2] - prefix[l - 1]));
		}
		cout << answer << " ";
	}
}
