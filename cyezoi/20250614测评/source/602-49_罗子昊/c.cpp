#include<bits/stdc++.h>
using namespace std;
int n,h[5010],dp[5010][5010];
int main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
		dp[1][i]=0;
		if(i>1){
			dp[2][i-1]=abs(h[i-1]-h[i]);
		}
	}
	for(int len=1;len<=2;len++){
		int mn=INT_MAX;
		for(int l=1;l<=n-len+1;l++){
			mn=min(mn,dp[len][l]);
		}
		printf("%d ",mn);
	}
	for(int len=3;len<=n;len++){
		int mn=INT_MAX;
		for(int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			dp[len][l]=dp[len-2][l+1]+abs(h[l]-h[r]);
			mn=min(mn,dp[len][l]);
		}
		printf("%d ",mn);
	}
}
