#include<bits/stdc++.h>
using namespace std;
int dp[3010][101][101][2];//0 1
int n,m;
int a[3010];
int b[101];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0][0][0]=0;
	dp[0][0][0][1]=0;
	a[n+1]=0;
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=m;k++){
				if(j==0&&k==0){
					dp[i][j][k][1]=dp[i-1][j][k][0]+a[i];
					dp[i][j][k][0]=max(dp[i-1][j][k][0],dp[i-1][j][k][1]);
				}else if(j==0){
					dp[i][j][k][1]=max(max(dp[i-1][j][k][0],dp[i-1][j][k-1][0]),dp[i-1][j][k-1][1])+a[i];
					dp[i][j][k][0]=max(dp[i-1][j][k][0],dp[i-1][j][k][1]);
				}else if(k==0){
					dp[i][j][k][1]=dp[i-1][j][k][0]+a[i];
					dp[i][j][k][0]=max(max(dp[i-1][j][k][0],dp[i-1][j-1][k][0]),dp[i-1][j][k][1]);
				}else{
					dp[i][j][k][1]=max(max(dp[i-1][j][k][0],dp[i-1][j][k-1][0]),dp[i-1][j][k-1][1])+a[i];
					dp[i][j][k][0]=max(max(dp[i-1][j][k][0],dp[i-1][j-1][k][0]),dp[i-1][j][k][1]);
				}
				//cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k][0]<<" "<<dp[i][j][k][1]<<'\n';
				
			}
		}
	}
	int ans=0;
	sort(b+1,b+m+1,greater<int>());
	for(int i=1;i<=m;i++){
		b[i]+=b[i-1];
	}
	for(int j=0;j<=m;j++){
		for(int k=0;k<=m;k++){
			if(j+k==m){
				ans=max(ans,max(dp[n+1][j][k][0],dp[n+1][j][k][1])+b[j]);
			}else if(j+k<m){
				ans=max(ans,max(dp[n+1][j][k][0],dp[n+1][j][k][1])+b[min(m,j+(m-j-k)/2)]);
			}
		}
	}
	cout<<ans;
}
