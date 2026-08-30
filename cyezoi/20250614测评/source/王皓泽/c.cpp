#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[5010][5010]; // wtf how did i find out how to dp this bullsh*t
signed main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	cout << 0 << ' '; // lol idk why they need this
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= n - i + 1; j++) {
			dp[i][j] = dp[i - 2][j + 1] + abs(nums[j] - nums[j + i - 1]);
		}
		int minVal = INT_MAX;
		for(int j = 1; j <= n - i + 1; j++) {
			minVal = min(minVal, dp[i][j]);
		}
		cout << minVal << ' ';
	}
	/*
	cout << "\n\n";
	for(int i = 1; i <= n + 1; i++) {
		for(int j = 1; j <= n - i + 1; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	return 0;
}
/*
7
3 1 4 1 5 9 2
0 2 0 5 2 10 10

num	3 1 4 1 5 9 2

	1 2 3 4 5 6 7

1	0 0 0 0 0 0 0
2	2 3 3 4 4 7
3	1 0 1 8 3
4	5 7 9 5
5	2 9 10
6	13 10
7	10

dp[i][j] = dp[i - 2][j + 1] + |num[j] - num[j + i - 1]|

4
1 3 5 6
*/
