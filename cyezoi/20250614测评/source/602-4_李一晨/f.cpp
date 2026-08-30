#include<bits/stdc++.h>
int a[3005],b[105],dp[3005][2];
int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	int n;std::cin >> n;
	for (int i = 1;i <= n;i++) std::cin >> a[i];
	int m;std::cin >> m;
	for (int i = 1;i <= m;i++) std::cin >> b[i];
	if (m == 0) goto zEro;
	if (m == 1) goto oEn;
	zEro:for (int i = 1;i <= n;i++){
		dp[i][0] = std::max(dp[i - 1][0],dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + a[i];
	}
	std::cout << std::max(dp[n][0],dp[n][1]) << '\n';
	return 0;
	oEn:int ans = 0;
	for (int i = 1;i <= n;i++){
		memset(dp,0,sizeof(dp));
		for (int j = n;j >= i;j--) a[j + 1] = a[j];
		a[i] = b[1];++n;
		for (int i = 1;i <= n;i++){
			dp[i][0] = std::max(dp[i - 1][0],dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + a[i];
		}
		ans = std::max(ans,std::max(dp[n][0],dp[n][1]));
		for (int j = i;j <= n;j++) a[j] = a[j + 1];--n;
	}
	std::cout << ans << '\n';
	return 0;
}
