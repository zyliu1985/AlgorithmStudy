// this is for m = 0, which gives 20% * 600 = 120 pts (im very sure that my maths is correct)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10000], dp[10000];
signed main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		if(i == 1) {
			dp[i] = a[i];
		} else {
			dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
		}
	}
	int maxVal = INT_MIN;
	for(int i = 1; i <= n; i++) {
		maxVal = max(maxVal, dp[i]);
	}
	cout << maxVal;
	return 0;
}
/*
10 1 12 2 8 6 14 7
*/
