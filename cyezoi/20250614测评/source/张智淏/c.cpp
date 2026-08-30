#include<bits/stdc++.h>
using namespace std;
int n,h[5005],dp[5005][5005],ans[5005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	for(int i=1;i<=n;i++){
		ans[i]=2e9;
	}
	ans[1]=0;
	for(int i=1;i<n;i++){
		dp[i][2]=abs(h[i]-h[i+1]);
		ans[2]=min(ans[2],dp[i][2]);
	}
	for(int i=3;i<=n;i++){
		for(int j=(i+1)/2;j+(i/2)<=n;j++){
			dp[j][i]=dp[j][i-2]+abs(h[j-(i-1)/2]-h[j+i/2]);
			ans[i]=min(ans[i],dp[j][i]);
		}	
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
