#include<bits/stdc++.h>
using namespace std;
int n,m,a[3005],b[105],dp[3005][2],ans,t1,t2,cnt;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(m==0){
		for(int i=1;i<=n;++i){
			dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
			dp[i][1]=dp[i-1][0]+a[i];
		}
		cout<<max(dp[n][1],dp[n][0]);
		return 0;
	}
	if(m==1){
		for(int i=1;i<=m;++i) cin>>b[i];
		for(int j=0;j<=n;++j){
			for(int i=0;i<=n;++i) dp[i][0]=dp[i][1]=0;
			if(j==0) dp[0][1]=b[1];
			for(int i=1;i<=n;++i){
				dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
				dp[i][1]=dp[i-1][0]+a[i];
				if(j==i){
					t1=dp[i][0],t2=dp[i][1];
					dp[i][0]=max(t1,t2);
					dp[i][1]=t1+b[1];
				}
			}
			ans=max(ans,max(dp[n][1],dp[n][0]));
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
