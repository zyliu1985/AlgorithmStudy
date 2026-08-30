#include<bits/stdc++.h>
using namespace std;
int n,m,a[3005],dp[3005][2],b[3010],x,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	if(m==0){
		for(int i=1;i<=n;i++){
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			dp[i][1]=dp[i-1][0]+a[i];
		}
		printf("%d",max(dp[n][0],dp[n][1]));
	}
	if(m==1){
		scanf("%d",&x);
		for(int i=1;i<=n+1;i++){
			for(int j=1;j<=n+1;j++){
				if(j<i)b[j]=a[j];
				else if(j==i)b[j]=x;
				else b[j]=a[j-1];
			}
			for(int j=1;j<=n+1;j++){
				dp[j][0]=max(dp[j-1][0],dp[j-1][1]);
				dp[j][1]=dp[j-1][0]+b[j];
			}
			ans=max(ans,max(dp[n+1][0],dp[n+1][1]));
		}
		printf("%d",ans);
	}
	return 0;
}
