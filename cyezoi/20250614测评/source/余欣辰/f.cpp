# include <bits/stdc++.h>
using namespace std;
int n,a[3010],m,b[110],dp[2][300010],mix=100010,mxx=0;
int main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		mix=min(mix,a[i]);
		mxx=max(a[i],mxx);
	}
	cin >> m;
	for (int i=1;i<=m;i++){cin >> b[i];}
	if (m==0){
		for (int i=1;i<=n;i++){
			dp[0][i]=max(dp[0][i],max(dp[1][i-1],dp[0][i-1]));
			dp[1][i]=max(dp[1][i],dp[0][i-1]+a[i]);
		}
		cout << max(dp[0][n],dp[1][n]);
		return 0;
	}
	if (m==1){
		if (b[1]<=mix){
			for (int i=1;i<=n;i++){
				dp[0][i]=max(dp[0][i],max(dp[1][i-1],dp[0][i-1]));
				dp[1][i]=max(dp[1][i],dp[0][i-1]+a[i]);
			}
			cout << max(dp[0][n],dp[1][n]);
			return 0;
		}
		if (b[1]>mxx){
			for (int i=1;i<=n;i++){
				dp[0][i]=max(dp[0][i],max(dp[1][i-1],dp[0][i-1]));
				dp[1][i]=max(dp[1][i],dp[0][i-1]+a[i]);
			}
			cout << max(dp[0][n],dp[1][n])-mix+b[1];
			return 0;
		}
	}
	return 0;
}
