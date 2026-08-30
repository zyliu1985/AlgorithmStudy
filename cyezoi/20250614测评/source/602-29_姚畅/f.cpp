#include <bits/stdc++.h>
using namespace std;
int n,m,a[3010],b[114],dp[3010],c[3010];
void solve0(){
	int dp[3010][4];
	memset(dp,0,sizeof(dp));
	dp[1][1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][2]);
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i];
		dp[i][2]=dp[i-1][1];
	}
	cout << max(dp[n][0],max(dp[n][1],dp[n][2]));
}
void solve1(){
	int ans=0;
	int dp[3010][4];
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<i;j++)c[j]=a[j];
		c[i]=b[1];
		for(int j=i+1;j<=n+1;j++)c[j]=a[j-1];
		
		int dp[3010][4];
		memset(dp,0,sizeof(dp));
		dp[1][1]=c[1];
		for(int j=2;j<=n+1;j++){
			dp[j][0]=max(dp[j-1][0],dp[j-1][2]);
			dp[j][1]=max(dp[j-1][0],dp[j-1][2])+c[j];
			dp[j][2]=dp[j-1][1];
		}
		ans=max(ans,max(dp[n+1][0],max(dp[n+1][1],dp[n+1][2])));
	}
	cout << ans;
	
}
int main(){
	//freopen("data.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n>>m;
	for(int i=1;i<=n;i++)cin >>a[i];
	for(int i=1;i<=m;i++)cin >>b[i];
	if(m==0)solve0();
	else if(m==1)solve1();
	return 0;
}
