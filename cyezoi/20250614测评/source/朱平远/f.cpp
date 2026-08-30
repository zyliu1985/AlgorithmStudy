//600pts * 20% = 120pts
#include <bits/stdc++.h>
using namespace std;
int n;
int a;
int dp[3005];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a;
		if(i == 1)
		{
			dp[i] = a;
			continue;
		}
		dp[i] = dp[i - 1];
		for(int j = 0; j < i - 1; j++)
			dp[i] = max(dp[i], dp[j] + a);
	}
	cout << dp[n];
}
/*
5
20 1 3 100 5


4
1 10 11 3


4
5 11 10 1
*/
