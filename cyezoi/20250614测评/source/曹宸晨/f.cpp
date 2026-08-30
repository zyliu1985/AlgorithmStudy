#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 3;
int n,m,a[N],b[N];
signed main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i = 1; i <= m; i++) scanf("%d",&b[i]);
	if(m == 0)
	{
		vector <int> dp(N,0);
		dp[1] = a[1];
		for(int i = 2; i <= n; i++)
			dp[i] = max(dp[i - 1],dp[i - 2] + a[i]);
		printf("%d",dp[n]);
		return 0;
	}
	if(m == 1)
	{
		vector < vector <int> > dp(N, vector <int> (N,0) );
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			dp[i][1] = (i == 1 ? b[1] : a[1]);
			ans = max(ans,dp[i][1]);
			for(int j = 2; j <= n + 1; j++)
			{
				int now = 0;
				if(j == i) now = b[j];
				if(j <  i) now = a[j];
				if(j >  i) now = a[j - 1];
				dp[i][j] = max(dp[i][j - 1],dp[i][j - 2] + now);
				ans = max(ans,dp[i][j]);
			}
		}
		printf("%d",ans);
		return 0;
	}
}
